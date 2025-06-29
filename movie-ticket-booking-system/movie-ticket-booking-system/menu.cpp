#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "menu.h"
#include "booking.h"
#include "movie.h"
#include "VisualFunctions.h"

void displayMenu() {
    printLogo("logo.txt");
    std::cout << "\n==== Movie Ticket Booking System ====\n";
    std::cout << "1. Search Movies\n";
    std::cout << "2. Book Tickets\n";
    std::cout << "3. View Booking History\n";
    std::cout << "4. Access Admin Panel\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

void searchMovies(const std::vector<Movie>& movies) {
    int option;
    std::cout << "\nSearch by:\n";
    std::cout << "1. Title\n2. Language\n3. Genre\n4. Release Date\n";
    std::cout << "Enter option: ";
    std::cin >> option;
    std::cin.ignore();

    std::string input;
    switch (option) {
    case 1:
        std::cout << "\nAvailable movie titles:\n";
        for (const auto& m : movies) std::cout << "- " << m.title << '\n';
        std::cout << "Enter movie title: ";
        break;
    case 2:
        std::cout << "\nAvailable languages:\n";
        for (const auto& m : movies) std::cout << "- " << m.language << '\n';
        std::cout << "Enter language: ";
        break;
    case 3:
        std::cout << "\nAvailable genres:\n";
        for (const auto& m : movies) std::cout << "- " << m.genre << '\n';
        std::cout << "Enter genre: ";
        break;
    case 4:
        std::cout << "\nAvailable release dates:\n";
        for (const auto& m : movies) std::cout << "- " << m.releaseDate << '\n';
        std::cout << "Enter release date: ";
        break;
    default:
        std::cout << "Invalid option.\n";
        return;
    }

    std::getline(std::cin, input);
    bool found = false;

    for (const auto& movie : movies) {
        bool match = (option == 1 && movie.title == input) ||
            (option == 2 && movie.language == input) ||
            (option == 3 && movie.genre == input) ||
            (option == 4 && movie.releaseDate == input);

        if (match) {
            displayMovieDetails(movie);
            found = true;
        }
    }

    if (!found) {
        std::cout << "No matching movies found.\n";
    }
}

void accessAdminPanel() {
    std::cout << "[Mocked] Admin panel access not yet implemented.\n";
}

void processPayment(bool isOnline) {
    std::cout << "\nSelect Payment Method:\n";
    if (isOnline) {
        std::cout << "1. Credit Card\n";
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            std::cout << "Processing credit card payment...\n";
        }
        else {
            std::cout << "Invalid payment method for online booking.\n";
        }
    }
    else {
        std::cout << "1. Credit Card\n2. Cash\n";
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            std::cout << "Processing credit card payment...\n";
        }
        else if (choice == 2) {
            std::cout << "Processing cash payment...\n";
        }
        else {
            std::cout << "Invalid payment method.\n";
        }
    }
}
