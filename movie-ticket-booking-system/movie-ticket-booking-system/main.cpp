#include <iostream>
#include <vector>
#include "menu.h"
#include "movie.h"
#include "auth.h"
#include "booking.h"
#include "cinema.h"   // Include this for initializeAllSeats()

std::vector<Movie> movies = {
    {"Inception", "English", "Sci-Fi", "2010-07-16"},
    {"Parasite", "Korean", "Thriller", "2019-05-30"},
    {"The Godfather", "English", "Crime", "1972-03-24"}
};

int main() {
    int authChoice;
    do {
        std::cout << "==== Welcome ====\n";
        std::cout << "1. Login\n";
        std::cout << "2. Sign Up\n";
        std::cout << "3. Exit\n";
        std::cout << "Choose option: ";
        std::cin >> authChoice;

        if (authChoice == 1) {
            if (login()) {
                initializeAllSeats();  // Initialize seats once logged in
                break;
            }
            else {
                std::cout << "Press Enter to try again...";
                std::cin.ignore();
                std::cin.get();
                system("CLS");
            }
        }
        else if (authChoice == 2) {
            signUp();
            std::cout << "Press Enter to continue...";
            std::cin.ignore();
            std::cin.get();
            system("CLS");
        }
        else if (authChoice == 3) {
            return 0;
        }
        else {
            std::cout << "Invalid option.\n";
        }
    } while (true);

    int choice;
    do {
        displayMenu();
        std::cin >> choice;
        system("CLS");

        switch (choice) {
        case 1:
            searchMovies(movies);
            break;
        case 2:
            bookTickets();
            break;
        case 3:
            viewBookingHistory();
            break;
        case 4:
            accessAdminPanel();
            break;
        case 5:
            std::cout << "Exiting. Thank you!\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
        if (choice != 5) {
            std::cout << "Press Enter to continue...";
            std::cin.ignore();
            std::cin.get();
            system("CLS");
        }
    } while (choice != 5);

    return 0;
}
