#include <iostream>
#include <string>
#include <vector>
#include "admin.h"
#include "cinema.h"
#include "movie.h"

// Link with globals declared elsewhere
extern std::vector<Cinema> cinemas;
extern std::vector<Movie> movies;

extern void initializeSeats(std::vector<Seat>& seats);

void addShow(const std::string& cinemaName, const std::string& hallName, const std::string& showtime) {
    for (auto& cinema : cinemas) {
        if (cinema.name == cinemaName) {
            for (auto& hall : cinema.halls) {
                if (hall.name == hallName) {
                    // Check if showtime already exists
                    for (const auto& show : hall.shows) {
                        if (show.time == showtime) {
                            std::cout << "Showtime already exists.\n";
                            return;
                        }
                    }
                    Show newShow;
                    newShow.time = showtime;
                    newShow.hall = hallName;
                    initializeSeats(newShow.seats);
                    hall.shows.push_back(newShow);
                    std::cout << "Show added successfully.\n";
                    return;
                }
            }
            std::cout << "Hall not found.\n";
            return;
        }
    }
    std::cout << "Cinema not found.\n";
}

void deleteShow(const std::string& cinemaName, const std::string& hallName, const std::string& showtime) {
    for (auto& cinema : cinemas) {
        if (cinema.name == cinemaName) {
            for (auto& hall : cinema.halls) {
                if (hall.name == hallName) {
                    auto& shows = hall.shows;
                    for (auto it = shows.begin(); it != shows.end(); ++it) {
                        if (it->time == showtime) {
                            shows.erase(it);
                            std::cout << "Show deleted successfully.\n";
                            return;
                        }
                    }
                    std::cout << "Showtime not found.\n";
                    return;
                }
            }
            std::cout << "Hall not found.\n";
            return;
        }
    }
    std::cout << "Cinema not found.\n";
}

void updateShow(const std::string& cinemaName, const std::string& hallName, const std::string& oldShowtime, const std::string& newShowtime) {
    for (auto& cinema : cinemas) {
        if (cinema.name == cinemaName) {
            for (auto& hall : cinema.halls) {
                if (hall.name == hallName) {
                    for (auto& show : hall.shows) {
                        if (show.time == oldShowtime) {
                            // Check if new showtime conflicts with existing shows
                            for (const auto& s : hall.shows) {
                                if (s.time == newShowtime) {
                                    std::cout << "New showtime conflicts with existing show.\n";
                                    return;
                                }
                            }
                            show.time = newShowtime;
                            std::cout << "Show updated successfully.\n";
                            return;
                        }
                    }
                    std::cout << "Old showtime not found.\n";
                    return;
                }
            }
            std::cout << "Hall not found.\n";
            return;
        }
    }
    std::cout << "Cinema not found.\n";
}

void addMovie(const Movie& movie) {
    // Check if movie title exists
    for (const auto& m : movies) {
        if (m.title == movie.title) {
            std::cout << "Movie already exists.\n";
            return;
        }
    }
    movies.push_back(movie);
    std::cout << "Movie added successfully.\n";
}

void deleteMovie(const std::string& title) {
    for (auto it = movies.begin(); it != movies.end(); ++it) {
        if (it->title == title) {
            movies.erase(it);
            std::cout << "Movie deleted successfully.\n";
            return;
        }
    }
    std::cout << "Movie not found.\n";
}
