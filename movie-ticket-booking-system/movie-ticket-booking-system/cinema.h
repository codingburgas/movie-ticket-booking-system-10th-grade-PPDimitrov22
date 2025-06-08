#pragma once
#ifndef CINEMA_H
#define CINEMA_H

#include <string>
#include <vector>
#include "movie.h"

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

void printShow(const Show& show);
void printHall(const Hall& hall);
void printCinemaDetails(const Cinema& cinema);
bool hasShowtime(const Cinema& cinema, const std::string& time);

#endif
