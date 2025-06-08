#include <iostream>
#include <string>
#include "booking.h"
#include "cinema.h"

void displayShowtimes(const Cinema& cinema, const std::string& movieTitle) {
    bool found = false;
    std::cout << "Available showtimes for '" << movieTitle << "' in " << cinema.name << ":\n";
    for (const auto& hall : cinema.halls) {
        for (const auto& show : hall.shows) {
            std::cout << hall.name << " | Showtime: " << show.time << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No showtimes available for this movie." << std::endl;
    }
}

void bookTickets() {
    std::string movieTitle;
    std::string selectedHall;
    std::string selectedTime;
    int bookingType;

    std::cout << "Enter the movie title you want to book: ";
    std::cin.ignore();
    std::getline(std::cin, movieTitle);

    for (const auto& cinema : cinemas) {
        displayShowtimes(cinema, movieTitle);
    }

    std::cout << "Enter the hall and time you want to book (e.g., Hall 1, 10:00): ";
    std::getline(std::cin, selectedHall);
    std::getline(std::cin, selectedTime);

    std::cout << "Select booking type: 1. Online, 2. Walk-in: ";
    std::cin >> bookingType;

    if (bookingType == 1) {
        std::string gmail;
        std::cout << "Online booking selected. Enter your gmail: ";
        std::cin.ignore();
        std::getline(std::cin, gmail);
        std::cout << "Booking successful. Confirmation sent to " << gmail << std::endl;
    }
    else if (bookingType == 2) {
        int paymentType;
        std::cout << "Select payment method: 1. Cash, 2. Credit Card: ";
        std::cin >> paymentType;

        if (paymentType == 1) {
            std::cout << "Booking successful with cash." << std::endl;
        }
        else if (paymentType == 2) {
            std::string creditCard;
            std::cout << "Enter credit card number: ";
            std::cin.ignore();
            std::getline(std::cin, creditCard);
            std::cout << "Booking successful with card: " << creditCard << std::endl;
        }
        else {
            std::cout << "Invalid payment method." << std::endl;
        }
    }
    else {
        std::cout << "Invalid booking type." << std::endl;
    }
}

void viewBookingHistory() {
    std::cout << "[Mocked] Booking history feature not implemented yet.\n";
}
