#include <iostream>
#include "menu.h"

void displayMenu() {
    std::cout << "==================== Movie Ticket Booking System ====================" << std::endl;
    std::cout << "1. Search Movies" << std::endl;
    std::cout << "2. Book Tickets" << std::endl;
    std::cout << "3. View Booking History" << std::endl;
    std::cout << "4. Admin Panel" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "=====================================================================" << std::endl;
    std::cout << "Enter your choice: ";
}