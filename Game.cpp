#include "Game.hpp"
#include <iostream>


bool Game::start()
{
    bool begin = false;
    char userInput;
    std::cout << "New Game? (y/n)" << std::endl;
    std::cin >> userInput;
    if (userInput != 'y') {
        begin = false;
    }
    return begin;
}



void Game::play()
{
    int round = 0;
    int inputValue;
    bool scored;
    
    std::string input;
    score.reset();
    
    while (round < MAX_ROUNDS && playing)
    {
        scored = false;

        hand.roll();
        hand.sort();
        score.calScore(hand);

    //  Show Category Numbers
        score.displayScoreCard(score.Open);
        
        // Display dice
        hand.printHand();
    
    //  Loops for user input until a valid category is chosen or until user quits game
        while(!scored && playing)
        {
            std::cout << "\nPlease select an available category (1-13): " << std::endl;
            std::cin >> input;
            inputValue = getUserInput(input);
            if(inputValue > 0)
                scored = score.setScore(inputValue);
        }

        // Display current total score
        score.displayScoreCard(score.Closed);
         round++;
    }
    
    // Display final score
    std::cout << "\nFinal Score: " << score.scoreTotal() << std::endl;
}

int Game::getUserInput(std::string input)
{
    transform(input.begin(), input.end(), input.begin(), ::tolower);

    
    if (input == "q" || input == "quit")
    {
        playing = false;
        return 0;
    }
    else if (input == "s" || input == "score")
    {
        std::cout << "\nCurrent Score: " <<score.scoreTotal() << std::endl;
        return -1;
    }
    else if (input == "co")
    {
        score.displayScoreCard(score.Open);
        return -1;
    }
    else if (input == "cc")
    {
        score.displayScoreCard(score.Closed);
        return -1;
    }
    else if (input == "d")
    {
        hand.printHand();
        return -1;
    }
    else if (input == "i")
    {
        getInstructions();
        return -1;
    }
    else
        return intValidation(input); // TODO: Add functionality for multiple kinds of input
}

void Game::getInstructions()
{
    std::cout << "To view your scorecard enter:\n\t"
                <<"*  \"cc\" for categories you've scored in or,\n\t"
                <<"*  \"co\" for categories that are still open.\n\t"
                <<"*  \"s\" or \"score\" for your current total score.\n\t"
                <<"*  \"i\" to repeat instructions." << std::endl;
    std::cout << "\tEnter \"d\" display the dice." << std::endl;
    std::cout << "\tEnter \"q\" at to quit at any time.\n" << std::endl;

}

void Game::continuePlaying(std::string input)
{
    transform(input.begin(), input.end(), input.begin(), ::tolower);

    
    if (input == "y" || input == "yes") {}
    else if (input == "n" || input == "no" || input == "q" || input == "quit")
    {
        playing = false;
    }
    else
    {
        std::cout << "\n\"" << input << "\"" << " is not a valid input. Try again later.\n" <<std::endl;
        playing = false;
    }
}

int Game::intValidation(std::string input)
{
    int inputValue;
    try
    {
        inputValue = std::stoi(input);
    }
    catch(const std::exception& e)
    {
        std::cout << "\"" << input << "\"" << " not valid, please try again." <<std::endl;
        return -1;
    }
    return inputValue;
}

bool Game::stringValidation(std::string input)
{
    if (input == "y" || input == "yes")
        return true;
    else if (input == "n" || input == "no")
    {
        playing = false;
        return true;
    }
    else
    {
        std::cout << "\"" << input << "\"" << " is not a valid input, please try again." <<std::endl;
        return false;
    }
}
