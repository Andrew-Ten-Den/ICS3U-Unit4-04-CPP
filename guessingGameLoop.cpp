// Copyright (c) 2022 St. Mother Teresa HS All rights reserved.
//
// Created by: Andrew Ten-Den
// Created on: April 2022
// This program lets the user try and guess the correct number between 0 and 9


#include <iostream>
#include <random>
#include <string>


int main() {
    // this function lets the user guess a random number between 0 and 9
    int guessCounter = 1;
    int guessedNumberAsInteger = 0;
    int someRandomNumber;
    std::string guessedNumberAsString;

    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);  // [0,9]
    someRandomNumber = idist(rgen);

    // input
    while (true) {
        std::cout << "Guess a number between 0 and 9: ";
        std::cin >> guessedNumberAsString;
        // process
        try {
            guessedNumberAsInteger = std::stoi(guessedNumberAsString);
            if (guessedNumberAsInteger == someRandomNumber) {
                // output
                std::cout << "You guessed correct after "
                << guessCounter << " guesses.";
                break;
            } else if (guessedNumberAsInteger < 0 ||
            guessedNumberAsInteger > 9) {
                // output
                std::cout << "Not between 0 and 9.\n";
                guessCounter = guessCounter + 1;
            } else if (guessedNumberAsInteger != someRandomNumber) {
                // output
                std::cout << "You guessed wrong! Try again.\n";
                guessCounter = guessCounter + 1;
            } else {
                // output
                std::cout << "Undefined.";
                guessCounter = guessCounter + 1;
            }
        } catch (std::invalid_argument) {
            std::cout << "That was not a valid integer.\n";
            guessCounter = guessCounter + 1;
        }
    }
    std::cout << "\nDone." << std::endl;
}
