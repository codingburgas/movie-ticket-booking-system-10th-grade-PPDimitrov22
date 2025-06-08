#include <iostream>
#include <vector>
#include "menu.h"
#include "movie.h"

std::vector<Movie> movies = {
    {"Inception", "English", "Sci-Fi", "2010-07-16"},
    {"Parasite", "Korean", "Thriller", "2019-05-30"},
    {"The Godfather", "English", "Crime", "1972-03-24"}
};

int main() {
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
    } while (choice != 5);

    return 0;
}
