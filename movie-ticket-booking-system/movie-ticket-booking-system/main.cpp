#include <iostream>
#include "menu.h"

int main() {
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Searching Movies..." << std::endl;
            break;
        case 2:
            std::cout << "Booking Tickets..." << std::endl;
            break;
        case 3:
            std::cout << "Viewing Booking History..." << std::endl;
            break;
        case 4:
            std::cout << "Accessing Admin Panel..." << std::endl;
            break;
        case 5:
            std::cout << "Exiting the system. Thank you!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);
    return 0;
}