#include <iostream>
#include <vector>
#include <string>
#include "menu.h"

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
            std::cout << "Hall: " << hall.name << " | Showtime: " << show.time << std::endl;
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
        std::string creditCard;
        std::cout << "Online booking selected. Enter your credit card number: ";
        std::cin.ignore();
        std::getline(std::cin, creditCard);
        std::cout << "Booking successful with credit card: " << creditCard << std::endl;
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
void searchMovies(const std::vector<Movie>& movies) {
    std::string searchTerm;
    std::cout << "Enter movie title, language, genre, or release date to search: ";
    std::cin.ignore();
    std::getline(std::cin, searchTerm);

    std::cout << "Search Results:\n";
    for (const auto& movie : movies) {
        if (movie.title.find(searchTerm) != std::string::npos ||
            movie.language.find(searchTerm) != std::string::npos ||
            movie.genre.find(searchTerm) != std::string::npos ||
            movie.releaseDate.find(searchTerm) != std::string::npos) {
            std::cout << "Title: " << movie.title
                << ", Language: " << movie.language
                << ", Genre: " << movie.genre
                << ", Release Date: " << movie.releaseDate << std::endl;
        }
    }
}
void viewBookingHistory() {
    std::cout << "Viewing Booking History..." << std::endl;
}

void accessAdminPanel() {
    std::cout << "Accessing Admin Panel..." << std::endl;
}

void displayMenu() {
    std::cout << "==================== Movie Ticket Booking System ====================" << std::endl;
    std::cout << "1. Search Movies" << std::endl;
    std::cout << "2. Book Tickets" << std::endl;
    std::cout << "3. View Booking History" << std::endl;
    std::cout << "4. Admin Panel" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "=====================================================================" << std::endl;
    std::cout << "Enter your choice: ";
}
