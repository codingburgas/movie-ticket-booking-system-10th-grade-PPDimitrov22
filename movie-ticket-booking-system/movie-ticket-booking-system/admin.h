#pragma once
#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include "movie.h"

void addShow(const std::string& cinemaName, const std::string& hallName, const std::string& showtime);
void deleteShow(const std::string& cinemaName, const std::string& hallName, const std::string& showtime);
void updateShow(const std::string& cinemaName, const std::string& hallName, const std::string& oldShowtime, const std::string& newShowtime);

void addMovie(const Movie& movie);
void deleteMovie(const std::string& title);

#endif
