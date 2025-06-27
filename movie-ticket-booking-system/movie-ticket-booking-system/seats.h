#pragma once
#ifndef SEATS_H
#define SEATS_H

#include <string>
#include <vector>
#include "cinema.h"

void displaySeats(const std::vector<Seat>& seats);
bool isSeatAvailable(const std::vector<Seat>& seats, const std::string& seatLabel);
bool bookSeat(std::vector<Seat>& seats, const std::string& seatLabel);

#endif
