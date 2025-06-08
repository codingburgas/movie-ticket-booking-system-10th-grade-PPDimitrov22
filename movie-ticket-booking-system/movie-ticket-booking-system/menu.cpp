#include <iostream>
#include <vector>
#include <string>
#include "menu.h"
#include "booking.h"
#include "movie.h"

extern std::vector<Movie> movies; 

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

void searchMovies(const std::vector<Movie>& movies) {
    std::cout << "Available Movies:\n";
    for (size_t i = 0; i < movies.size(); ++i) {
        std::cout << (i + 1) << ". " << movies[i].title << std::endl;
    }

    std::cout << "\nEnter the number corresponding to the movie you want to view: ";
    int choice;
    std::cin >> choice;

    if (choice < 1 || choice > static_cast<int>(movies.size())) {
        std::cout << "Invalid choice. Returning to the menu...\n";
        return;
    }

    const Movie& selectedMovie = movies[choice - 1];

    std::cout << "\nYou selected: " << selectedMovie.title << "\n";
    std::cout << "Language: " << selectedMovie.language << "\n";
    std::cout << "Genre: " << selectedMovie.genre << "\n";
    std::cout << "Release Date: " << selectedMovie.releaseDate << "\n\n";
}

void viewBookingHistory() {
    std::cout << "Viewing Booking History..." << std::endl;
}

void accessAdminPanel() {
    std::cout << "Accessing Admin Panel..." << std::endl;
}
