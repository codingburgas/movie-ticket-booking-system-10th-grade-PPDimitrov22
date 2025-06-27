#include <iostream>
#include "seats.h"

void displaySeats(const std::vector<Seat>& seats) {
    std::cout << "Seats (X = booked):\n";
    for (const auto& seat : seats) {
        std::cout << seat.seatNumber << "[" << seat.type[0] << "] ";
        if (seat.isBooked)
            std::cout << "X ";
        else
            std::cout << "O ";
    }
    std::cout << "\n";
}

bool isSeatAvailable(const std::vector<Seat>& seats, const std::string& seatLabel) {
    for (const auto& seat : seats) {
        if (seat.seatNumber == seatLabel) {
            return !seat.isBooked;
        }
    }
    return false; 
}

bool bookSeat(std::vector<Seat>& seats, const std::string& seatLabel) {
    for (auto& seat : seats) {
        if (seat.seatNumber == seatLabel && !seat.isBooked) {
            seat.isBooked = true;
            return true;
        }
    }
    return false;
}
