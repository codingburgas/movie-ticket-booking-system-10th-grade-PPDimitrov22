#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "menu.h"
#include "booking.h"
#include "movie.h"
#include "cinema.h"
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

    // Clear screen before showing options for all cases
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    switch (option) {
    case 1:
        std::cout << "Available movie titles:\n";
        for (const auto& m : movies)
            std::cout << "- " << m.title << '\n';
        std::cout << "\nEnter movie title: ";
        std::getline(std::cin, input);
        break;
    case 2:
        std::cout << "Available languages:\n";
        for (const auto& m : movies)
            std::cout << "- " << m.language << '\n';
        std::cout << "\nEnter language: ";
        std::getline(std::cin, input);
        break;
    case 3:
        std::cout << "Available genres:\n";
        for (const auto& m : movies)
            std::cout << "- " << m.genre << '\n';
        std::cout << "\nEnter genre: ";
        std::getline(std::cin, input);
        break;
    case 4:
        std::cout << "Available release dates:\n";
        for (const auto& m : movies)
            std::cout << "- " << m.releaseDate << '\n';
        std::cout << "\nEnter release date: ";
        std::getline(std::cin, input);
        break;
    default:
        std::cout << "Invalid option.\n";
        return;
    }

    // Clear screen again before displaying results
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

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
    std::cout << "\n=== Admin Panel ===\n";
    std::cout << "1. Add Show\n2. Delete Show\n3. Update Show\n";
    std::cout << "4. Add Movie\n5. Remove Movie\n";
    std::cout << "Enter option: ";
    int option;
    std::cin >> option;
    std::cin.ignore();

    extern std::vector<Movie> movies;

    std::string cinemaName, hallName, showTime;
    Show newShow;

    switch (option) {
    case 1:
        std::cout << "Enter Cinema Name: ";
        std::getline(std::cin, cinemaName);
        std::cout << "Enter Hall Name: ";
        std::getline(std::cin, hallName);
        std::cout << "Enter Show Time: ";
        std::getline(std::cin, newShow.time);
        newShow.hall = hallName;
        initializeSeats(newShow.seats);
        if (addShow(cinemas, cinemaName, hallName, newShow)) {
            std::cout << "Show added successfully.\n";
        }
        else {
            std::cout << "Failed to add show (may already exist).\n";
        }
        break;
    case 2:
        std::cout << "Enter Cinema Name: ";
        std::getline(std::cin, cinemaName);
        std::cout << "Enter Hall Name: ";
        std::getline(std::cin, hallName);
        std::cout << "Enter Show Time to delete: ";
        std::getline(std::cin, showTime);
        if (deleteShow(cinemas, cinemaName, hallName, showTime)) {
            std::cout << "Show deleted successfully.\n";
        }
        else {
            std::cout << "Failed to delete show (not found).\n";
        }
        break;
    case 3:
        std::cout << "Enter Cinema Name: ";
        std::getline(std::cin, cinemaName);
        std::cout << "Enter Hall Name: ";
        std::getline(std::cin, hallName);
        std::cout << "Enter Old Show Time to update: ";
        std::getline(std::cin, showTime);
        std::cout << "Enter New Show Time: ";
        std::getline(std::cin, newShow.time);
        newShow.hall = hallName;
        initializeSeats(newShow.seats);
        if (updateShow(cinemas, cinemaName, hallName, showTime, newShow)) {
            std::cout << "Show updated successfully.\n";
        }
        else {
            std::cout << "Failed to update show (not found).\n";
        }
        break;
    case 4: {  // Add movie
        Movie newMovie;
        std::cout << "Enter movie title: ";
        std::getline(std::cin, newMovie.title);
        std::cout << "Enter language: ";
        std::getline(std::cin, newMovie.language);
        std::cout << "Enter genre: ";
        std::getline(std::cin, newMovie.genre);
        std::cout << "Enter release date: ";
        std::getline(std::cin, newMovie.releaseDate);

        movies.push_back(newMovie);
        std::cout << "Movie added successfully.\n";
        break;
    }
    case 5: {  // Remove movie
        std::string titleToRemove;
        std::cout << "Enter movie title to remove: ";
        std::getline(std::cin, titleToRemove);

        auto it = std::remove_if(movies.begin(), movies.end(), [&](const Movie& m) {
            return m.title == titleToRemove;
            });

        if (it != movies.end()) {
            movies.erase(it, movies.end());
            std::cout << "Movie removed successfully.\n";
        }
        else {
            std::cout << "Movie not found.\n";
        }
        break;
    }
    default:
        std::cout << "Invalid admin option.\n";
    }
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
