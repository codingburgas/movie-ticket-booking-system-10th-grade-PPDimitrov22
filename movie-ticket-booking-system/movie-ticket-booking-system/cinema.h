#pragma once
#include <string>
#include <vector>

struct Seat {
    std::string seatNumber;
    std::string type;
    double price;
    bool isBooked = false;
};

struct Show {
    std::string time;
    std::string hall;
    std::vector<Seat> seats;
};

struct Hall {
    std::string name;
    std::vector<Show> shows;
};

struct Cinema {
    std::string name;
    std::vector<Hall> halls;
};

extern std::vector<Cinema> cinemas;

void initializeSeats(std::vector<Seat>& seats);
void initializeAllSeats();

bool addShow(std::vector<Cinema>& cinemas, const std::string& cinemaName, const std::string& hallName, const Show& newShow);
bool deleteShow(std::vector<Cinema>& cinemas, const std::string& cinemaName, const std::string& hallName, const std::string& showTime);
bool updateShow(std::vector<Cinema>& cinemas, const std::string& cinemaName, const std::string& hallName, const std::string& oldShowTime, const Show& updatedShow);
