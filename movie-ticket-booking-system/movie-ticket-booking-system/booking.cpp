#include <iostream>
#include <string>
#include <vector>
#include "booking.h"
#include "cinema.h"

std::vector<Cinema> cinemas = {
    {"Cinema 1", {
        {"Hall 1", {{"10:00", "Hall 1"}, {"13:00", "Hall 1"}}},
        {"Hall 2", {{"12:00", "Hall 2"}, {"15:00", "Hall 2"}}}
    }},
    {"Cinema 2", {
        {"Hall 1", {{"09:00", "Hall 1"}, {"18:00", "Hall 1"}}},
        {"Hall 2", {{"11:00", "Hall 2"}, {"14:00", "Hall 2"}}}
    }}
};

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

    std::cout << "Enter the hall you want to book (e.g., Hall 1): ";
    std::getline(std::cin, selectedHall);
    std::cout << "Enter the time you want to book (e.g., 10:00): ";
    std::getline(std::cin, selectedTime);

    std::cout << "Select booking type: 1. Online, 2. Walk-in: ";
    std::cin >> bookingType;

    if (bookingType == 1) {
        std::string gmail;
        std::cout << "Online booking selected. Enter your gmail so we can send you the bill: ";
        std::cin.ignore();
        std::getline(std::cin, gmail);
        std::cout << "Booking successful using online booking: " << gmail << std::endl;
    }
    else if (bookingType == 2) {
        int paymentType;
        std::cout << "Walk-in booking selected. Select payment method: 1. Cash, 2. Credit Card: ";
        std::cin >> paymentType;

        if (paymentType == 1) {
            std::cout << "Booking successful with Cash payment." << std::endl;
        }
        else if (paymentType == 2) {
            std::string creditCard;
            std::cout << "Enter your credit card number: ";
            std::cin.ignore();
            std::getline(std::cin, creditCard);
            std::cout << "Booking successful with credit card: " << creditCard << std::endl;
        }
        else {
            std::cout << "Invalid payment method." << std::endl;
        }
    }
    else {
        std::cout << "Invalid booking type." << std::endl;
    }
}
