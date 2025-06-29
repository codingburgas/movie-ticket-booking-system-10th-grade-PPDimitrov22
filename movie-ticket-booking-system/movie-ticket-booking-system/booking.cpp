#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "booking.h"
#include "cinema.h"
#include "seats.h"
#include "payment.h" // For processPayment

extern std::vector<Cinema> cinemas;

std::vector<std::string> bookingHistory;

void displayShowtimes(const Cinema& cinema, const std::string& movieTitle) {
    std::cout << "Showtimes for movie \"" << movieTitle << "\" at " << cinema.name << ":\n";
    for (const auto& hall : cinema.halls) {
        std::cout << hall.name << ": ";
        for (const auto& show : hall.shows) {
            std::cout << show.time << "  ";
        }
        std::cout << "\n";
    }
}

void bookTickets() {
    std::string cinemaName, movieTitle, selectedHall, selectedTime;

    std::cout << "Available cinemas:\n";
    for (const auto& c : cinemas) {
        std::cout << "- " << c.name << "\n";
    }
    std::cout << "Enter cinema name: ";
    std::cin.ignore();
    std::getline(std::cin, cinemaName);

    Cinema* chosenCinema = nullptr;
    for (auto& c : cinemas) {
        if (c.name == cinemaName) {
            chosenCinema = &c;
            break;
        }
    }
    if (!chosenCinema) {
        std::cout << "Cinema not found.\n";
        return;
    }

    std::cout << "Enter movie title: ";
    std::getline(std::cin, movieTitle);

    displayShowtimes(*chosenCinema, movieTitle);

    std::cout << "Enter hall name: ";
    std::getline(std::cin, selectedHall);

    std::cout << "Enter showtime (e.g. 10:00): ";
    std::getline(std::cin, selectedTime);

    // Find the show object
    Show* selectedShow = nullptr;
    for (auto& hall : chosenCinema->halls) {
        if (hall.name == selectedHall) {
            for (auto& show : hall.shows) {
                if (show.time == selectedTime) {
                    selectedShow = &show;
                    break;
                }
            }
        }
    }

    if (!selectedShow) {
        std::cout << "No show found for this hall and time.\n";
        return;
    }

    displaySeats(selectedShow->seats);

    std::vector<std::string> selectedSeats;
    std::string seatInput;

    std::cout << "Enter seat labels to book (type DONE to finish):\n";
    while (true) {
        std::cin >> seatInput;
        if (seatInput == "DONE") break;

        if (!isSeatAvailable(selectedShow->seats, seatInput)) {
            std::cout << "Seat " << seatInput << " is not available or invalid. Try again.\n";
        }
        else {
            if (std::find(selectedSeats.begin(), selectedSeats.end(), seatInput) == selectedSeats.end()) {
                selectedSeats.push_back(seatInput);
                std::cout << "Seat " << seatInput << " added to your booking.\n";
            }
            else {
                std::cout << "Seat " << seatInput << " is already selected.\n";
            }
        }
    }

    if (selectedSeats.empty()) {
        std::cout << "No seats selected. Booking cancelled.\n";
        return;
    }

    // Ask for booking method
    bool isOnline;
    std::string methodInput;
    std::cout << "Are you booking online or as a walk-in? (enter 'online' or 'walk-in'): ";
    std::cin >> methodInput;

    if (methodInput == "online") {
        isOnline = true;
    }
    else if (methodInput == "walk-in") {
        isOnline = false;
    }
    else {
        std::cout << "Invalid option. Booking cancelled.\n";
        return;
    }

    // Process payment
    if (!processPayment(isOnline)) {
        std::cout << "Payment failed. Booking cancelled.\n";
        return;
    }

    // Book seats
    for (const auto& seatLabel : selectedSeats) {
        bookSeat(selectedShow->seats, seatLabel);
    }

    std::cout << "Successfully booked seats: ";
    for (const auto& seatLabel : selectedSeats) {
        std::cout << seatLabel << " ";
    }
    std::cout << "\n";

    std::string bookingRecord = "Cinema: " + cinemaName + ", Movie: " + movieTitle + ", Hall: " + selectedHall + ", Time: " + selectedTime + ", Seats: ";
    for (const auto& seatLabel : selectedSeats) bookingRecord += seatLabel + " ";
    bookingHistory.push_back(bookingRecord);
}

void viewBookingHistory() {
    if (bookingHistory.empty()) {
        std::cout << "No bookings made yet.\n";
        return;
    }
    std::cout << "Booking History:\n";
    for (const auto& record : bookingHistory) {
        std::cout << record << "\n";
    }
}
