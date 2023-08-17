#include <iostream>
#include <cstdlib>     
#include <ctime>       
#include <vector>      
class Player {
public:
    Player() : guess(0), prize(0) {}
    
    int guess;
    int prize;
};
class Game {
public:
    Game() : minNumber(1), maxNumber(100), difficulty(1) {}
    
    int minNumber;
    int maxNumber;
    int difficulty;
    
    int generateRandomNumber() {
        return minNumber + rand() % (maxNumber - minNumber + 1);
    }
};
int main() {
    srand(time(0));  
    
    Player player;
    Game game;
    
    int targetNumber = game.generateRandomNumber();
    
    std::cout << "Welcome to the Guessing Game!\n";
    std::cout << "Guess the number between " << game.minNumber << " and " << game.maxNumber << ".\n";
    std::cout << "Enter your guess: ";
    std::cin >> player.guess;

    if (player.guess == targetNumber) {
        std::cout << "Congratulations! You guessed right.\n";
    } else {
        std::cout << "Sorry, your guess is incorrect.\n";
    }
    char playAgain;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> playAgain;

    if (playAgain != 'y' && playAgain != 'Y') {
        std::cout << "Thanks for playing!\n";
    } else {
        player.guess = 0;
        targetNumber = game.generateRandomNumber();
    }
    std::vector<int> prizeValues = {50, 100, 200};
    player.prize = prizeValues[game.difficulty - 1];
    return 0;
}