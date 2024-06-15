#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate a random number between 1 and 100 (adjust the range as needed)
    const int minNumber = 1;
    const int maxNumber = 100;
    int secretNumber = minNumber + std::rand() % (maxNumber - minNumber + 1); // range where the rand number is generated

    int userGuess;
    int x=0;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I've picked a number between " << minNumber << " and " << maxNumber << ". Try to guess it!" << std::endl;

    do {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        attempts++;

        if (userGuess < secretNumber) {
            std::cout << "Too low! Try a higher number." << std::endl;
        } else if (userGuess > secretNumber) {
            std::cout << "Too high! Try a lower number." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number (" << secretNumber << ") in " << attempts << " attempts." << std::endl;
        }
    } while (userGuess != secretNumber);

    return 0;
}
