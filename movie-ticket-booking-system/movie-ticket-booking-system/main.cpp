#include <iostream>
#include <vector>
#include "auth.h"
#include "menu.h"
#include "movie.h"
#include "booking.h"
#include "cinema.h"
#include "admin.h"

#ifdef _WIN32
#define CLEAR_SCREEN "CLS"
#else
#define CLEAR_SCREEN "clear"
#endif

std::vector<Movie> movies = {
    {"Inception", "English", "Sci-Fi", "2010-07-16"},
    {"Parasite", "Korean", "Thriller", "2019-05-30"},
    {"The Godfather", "English", "Crime", "1972-03-24"}
};

int main() {
    while (true) {  // Loop to restart program after logout

        system(CLEAR_SCREEN);  // Clear before showing login/signup menu

        int authChoice;
        UserType userType = UserType::None;

        do {
            std::cout << "==== Welcome ====\n";
            std::cout << "1. Login\n";
            std::cout << "2. Sign Up\n";
            std::cout << "3. Exit\n";
            std::cout << "Choose option: ";
            std::cin >> authChoice;

            if (authChoice == 1) {
                userType = login();

                if (userType == UserType::Admin) {
                    system(CLEAR_SCREEN);
                    std::cout << "Welcome, Admin!\n";
                    accessAdminPanel();
                    break;  // After admin panel, return to login/signup menu
                }
                else if (userType == UserType::Regular) {
                    initializeAllSeats();
                    break;
                }
                else {
                    std::cout << "Press Enter to try again...";
                    std::cin.ignore();
                    std::cin.get();
                    system(CLEAR_SCREEN);
                }
            }
            else if (authChoice == 2) {
                signUp();
                std::cout << "Press Enter to continue...";
                std::cin.ignore();
                std::cin.get();
                system(CLEAR_SCREEN);
            }
            else if (authChoice == 3) {
                return 0;
            }
            else {
                std::cout << "Invalid option.\n";
            }
        } while (true);

        if (userType == UserType::Regular) {
            int choice;
            do {
                displayMenu();
                std::cin >> choice;
                system(CLEAR_SCREEN);

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
                    std::cout << "Access Denied: Admins only.\n";
                    break;
                case 5:
                    std::cout << "Logging out...\n";
                    break;
                default:
                    std::cout << "Invalid choice. Try again.\n";
                }

                if (choice != 5) {
                    std::cout << "Press Enter to continue...";
                    std::cin.ignore();
                    std::cin.get();
                    system(CLEAR_SCREEN);
                }
            } while (choice != 5);
        }
    }
    return 0;
}
