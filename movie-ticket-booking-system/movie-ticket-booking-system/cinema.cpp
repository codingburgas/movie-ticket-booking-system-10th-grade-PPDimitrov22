#include <iostream>
#include "cinema.h"

void printShow(const Show& show) {
    std::cout << "Showtime: " << show.time << ", Hall: " << show.hall << std::endl;
}

void printHall(const Hall& hall) {
    std::cout << "Hall: " << hall.name << std::endl;
    for (const auto& show : hall.shows) {
        printShow(show);
    }
}

void printCinemaDetails(const Cinema& cinema) {
    std::cout << "Cinema: " << cinema.name << std::endl;
    for (const auto& hall : cinema.halls) {
        printHall(hall);
    }
}

bool hasShowtime(const Cinema& cinema, const std::string& time) {
    for (const auto& hall : cinema.halls) {
        for (const auto& show : hall.shows) {
            if (show.time == time) {
                return true;
            }
        }
    }
    return false;
}
