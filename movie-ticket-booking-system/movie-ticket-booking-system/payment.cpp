#include <iostream>
#include <string>
#include "payment.h"

bool processPayment(bool isOnline) {
    std::string method;
    if (isOnline) {
        std::cout << "Enter credit card number: ";
        std::string card;
        std::cin >> card;
        std::cout << "Processing online payment...\n";
        return true; 
    }
    else {
        std::cout << "Choose payment method (cash/credit): ";
        std::cin >> method;
        if (method == "cash" || method == "credit") {
            std::cout << "Processing " << method << " payment...\n";
            return true;
        }
        else {
            std::cout << "Invalid payment method.\n";
            return false;
        }
    }
}
