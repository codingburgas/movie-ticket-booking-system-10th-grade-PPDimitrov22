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

#endif