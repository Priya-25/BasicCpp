/* This is a simple text based game, in this, the game generates a random number between 1 and 100, 
and the player has to guess the number. After each guess, the game provides feedback on whether the 
guess was too high or too low. The game continues until the player correctly guesses the secret number.
*/




#include <iostream>
#include <cstdlib>   
#include <ctime>     

class GuessTheNumberGame {
public:
    GuessTheNumberGame() {
        
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        secretNumber = std::rand() % 100 + 1;  
    }

    void play() {
        std::cout << "Welcome to Guess the Number!\n";
        std::cout << "Can you guess the secret number between 1 and 100?\n\n";

        int guess;
        int attempts = 0;

        do {
            std::cout << "Enter your guess: ";
            std::cin >> guess;
            attempts++;

            if (guess < secretNumber) {
                std::cout << "Too low! Try again.\n";
            } else if (guess > secretNumber) {
                std::cout << "Too high! Try again.\n";
            } else {
                std::cout << "\nCongratulations! You guessed the number in " << attempts << " attempts!\n";
            }
        } while (guess != secretNumber);
    }

private:
    int secretNumber;
};

int main() {
    GuessTheNumberGame game;
    game.play();

    return 0;
}
