#pragma once
#ifndef CINEMA_H
#define CINEMA_H

#include <string>
#include <vector>

struct Seat {
    std::string seatNumber;
    std::string type;
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

#endif
