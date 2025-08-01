#include <iostream>
#include <fstream>
#include <string>
#include "auth.h"

const std::string ADMIN_USERNAME = "admin";
const std::string ADMIN_PASSWORD = "admin123";

UserType login() {
    std::string username, password, u, p;
    system("CLS");
    std::cout << "=== Login ===\n";
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (username == ADMIN_USERNAME && password == ADMIN_PASSWORD) {
        system("CLS");
        std::cout << "Admin login successful!\n";
        return UserType::Admin;
    }

    std::ifstream file("users.txt");
    while (file >> u >> p) {
        if (u == username && p == password) {
            system("CLS");
            std::cout << "Login successful!\n";
            return UserType::Regular;
        }
    }

    std::cout << "Invalid username or password.\n";
    return UserType::None;
}

void signUp() {
    std::string username, password, u, p;
    system("CLS");
    std::cout << "=== Sign Up ===\n";
    std::cout << "Enter a username: ";
    std::cin >> username;

    if (username == ADMIN_USERNAME) {
        std::cout << "Username reserved. Please choose another one.\n";
        return;
    }

    std::cout << "Enter a password: ";
    std::cin >> password;

    std::ifstream inFile("users.txt");
    while (inFile >> u >> p) {
        if (u == username) {
            std::cout << "Username already taken. Please choose another one.\n";
            return;
        }
    }
    inFile.close();

    std::ofstream outFile("users.txt", std::ios::app);
    if (outFile.is_open()) {
        outFile << username << " " << password << "\n";
        outFile.close();
        system("CLS");
        std::cout << "Sign up successful!\n";
    }
    else {
        std::cout << "Failed to open file.\n";
    }
}
