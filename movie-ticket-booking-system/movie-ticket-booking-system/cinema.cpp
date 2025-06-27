#include <iostream>
#include "cinema.h"

std::vector<Cinema> cinemas = {
    {
        "Cinema One", {
            {"Hall 1", {{"10:00", "Hall 1"}, {"12:00", "Hall 1"}}},
            {"Hall 2", {{"14:00", "Hall 2"}, {"16:00", "Hall 2"}}}
        }
    },
    {
        "Cinema Two", {
            {"Hall A", {{"11:00", "Hall A"}, {"13:00", "Hall A"}}}
        }
    }
};

void initializeSeats(std::vector<Seat>& seats) {
    seats.clear(); 
    for (int i = 1; i <= 3; ++i) {
        seats.push_back({ "S" + std::to_string(i), "Silver", false });
    }
    for (int i = 1; i <= 4; ++i) {
        seats.push_back({ "G" + std::to_string(i), "Gold", false });
    }
    for (int i = 1; i <= 3; ++i) {
        seats.push_back({ "P" + std::to_string(i), "Platinum", false });
    }
}

void initializeAllSeats() {
    for (auto& cinema : cinemas) {
        for (auto& hall : cinema.halls) {
            for (auto& show : hall.shows) {
                if (show.seats.empty()) {
                    initializeSeats(show.seats);
                }
            }
        }
    }
}

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
