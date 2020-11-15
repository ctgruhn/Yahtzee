#include <iostream>
#include <string>
#include <cstring>

#include "Dice.hpp"
#include "Scorecard.hpp"
#include "Game.hpp"

int main(int argc, const char * argv[])
{
    Game game;
//    game.titleCard();
    std::string input;
    game.getInstructions();

    //TODO: Step 1 - Ask user if they would like to start a new game
    std::cout << "Welcome to Yahtzee!" << std::endl;
    std::cout << "Ready? (y/n)" <<std::endl;
    std::cin >> input;
    game.continuePlaying(input);
    //TODO: Step 2 - Loop until user exits game
    while (game.isPlaying())
    {
    //TODO: Step 3 - Start game --> use Game class
        game.play();
    //TODO: Step 4 - Initial roll, 5 dice (Randomize 5 values) --> Use Die/Dice class

    //TODO: Step 5 - Display potential score based on dice rolls for each open category

    //TODO: Setp 6 - User may select a category to score in, begin new round with category locked (Return to Step 4 w/ 1 fewer categories)
    //TODO: Step 7 - User may select (or unselect) 0 to 5 dice to lock in for next round
    //TODO: Step 8 - Repeat step 4 (max 2 times) with unlocked dice 
    //TODO: Step 9 - Display final score
    //TODO: Step 10 - Ask user to play again
        std::cout << "\nWould you like to play again? (y/n)" << std::endl;  // Allows user to play again.
        std::cin >> input;
        game.continuePlaying(input);
    //TODO              if yes, clear score and selected categories, repeat step 3 (or 4)
    //TODO:             if no, exit game
        game.start();
     }

    std::cout << "\nThank you for playing!" << std::endl;

    return 0;

}
