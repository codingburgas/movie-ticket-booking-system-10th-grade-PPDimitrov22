#pragma once
#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include "cinema.h"

void displayShowtimes(const Cinema& cinema, const std::string& movieTitle);
void bookTickets();
void loadBookingHistory();
void viewBookingHistory();

#endif
