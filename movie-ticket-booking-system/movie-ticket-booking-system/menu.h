#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>

struct Movie {
    std::string title;
    std::string language;
    std::string genre;
    std::string releaseDate;
};

struct Show {
    std::string time;
    std::string hall;
};

struct Hall {
    std::string name;
    std::vector<Show> shows;
};

struct Cinema {
    std::string name;
    std::vector<Hall> halls;
};

void displayMenu();
void searchMovies(const std::vector<Movie>& movies);
void bookTickets();
void viewBookingHistory();
void accessAdminPanel();

#endif