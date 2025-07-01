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
        seats.push_back({ "S" + std::to_string(i), "Silver", 10.0, false });
    }
    for (int i = 1; i <= 3; ++i) {
        seats.push_back({ "G" + std::to_string(i), "Gold", 15.0, false });
    }
    for (int i = 1; i <= 3; ++i) {
        seats.push_back({ "P" + std::to_string(i), "Platinum", 20.0, false });
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

// Admin function implementations

bool addShow(std::vector<Cinema>& cinemas, const std::string& cinemaName, const std::string& hallName, const Show& newShow) {
    for (auto& cinema : cinemas) {
        if (cinema.name == cinemaName) {
            for (auto& hall : cinema.halls) {
                if (hall.name == hallName) {
                    // Check if show with same time exists
                    for (const auto& show : hall.shows) {
                        if (show.time == newShow.time) {
                            return false; // show already exists at this time
                        }
                    }
                    hall.shows.push_back(newShow);
                    return true;
                }
            }
        }
    }
    return false;
}

bool deleteShow(std::vector<Cinema>& cinemas, const std::string& cinemaName, const std::string& hallName, const std::string& showTime) {
    for (auto& cinema : cinemas) {
        if (cinema.name == cinemaName) {
            for (auto& hall : cinema.halls) {
                if (hall.name == hallName) {
                    for (auto it = hall.shows.begin(); it != hall.shows.end(); ++it) {
                        if (it->time == showTime) {
                            hall.shows.erase(it);
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool updateShow(std::vector<Cinema>& cinemas, const std::string& cinemaName, const std::string& hallName, const std::string& oldShowTime, const Show& updatedShow) {
    for (auto& cinema : cinemas) {
        if (cinema.name == cinemaName) {
            for (auto& hall : cinema.halls) {
                if (hall.name == hallName) {
                    for (auto& show : hall.shows) {
                        if (show.time == oldShowTime) {
                            show = updatedShow;
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}
