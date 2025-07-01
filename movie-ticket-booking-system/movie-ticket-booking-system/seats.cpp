#include <iostream>
#include <iomanip>
#include "seats.h"

void displaySeats(const std::vector<Seat>& seats) {
    std::vector<std::string> silver, gold, platinum;

    for (const auto& seat : seats) {
        std::string status = seat.isBooked ? "(X)" : "(O)";
        std::string label = seat.seatNumber + status;

        if (seat.type == "Silver") silver.push_back(label);
        else if (seat.type == "Gold") gold.push_back(label);
        else if (seat.type == "Platinum") platinum.push_back(label);
    }

    auto printRow = [](const std::vector<std::string>& row) {
        for (const auto& s : row) {
            std::cout << std::setw(12) << std::left << s;
        }
        std::cout << "\n";
        };

    std::cout << "\nAvailable Seats:\n\n";
    printRow(silver);
    printRow(gold);
    printRow(platinum);
    std::cout << "\n(O) = Available   (X) = Booked\n\n";
}

bool isSeatAvailable(const std::vector<Seat>& seats, const std::string& seatLabel) {
    for (const auto& seat : seats) {
        if (seat.seatNumber == seatLabel && !seat.isBooked) {
            return true;
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
