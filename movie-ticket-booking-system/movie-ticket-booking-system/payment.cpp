#include <iostream>
#include <string>
#include "payment.h"

bool isValidFormat(const std::string& cardNumber) {
    if (cardNumber.length() != 19) return false;
    for (size_t i = 0; i < cardNumber.length(); ++i) {
        if ((i + 1) % 5 == 0) {
            if (cardNumber[i] != '-') return false;
        }
        else {
            if (cardNumber[i] < '0' || cardNumber[i] > '9') return false;
        }
    }
    return true;
}

bool processPayment(bool isOnline) {
    std::string method;
    if (isOnline) {
        std::cout << "Enter credit card number (format XXXX-XXXX-XXXX-XXXX): ";
        std::string card;
        std::cin >> card;
        if (!isValidFormat(card)) {
            std::cout << "Invalid card format.\n";
            return false;
        }
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
