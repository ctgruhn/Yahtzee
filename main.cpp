#include <iostream>
#include <string>
#include <cstring>
 
template <class myType>
bool isValid(myType input, const char *compareArr, int arrLen)
{
     for (int i = 0; i < arrLen; i++)
     {
        if(input == compareArr[i])
            return true;
     }
     return false;
}

char getUserCommand()
{
    char userInput;
    int cout = 0;
    int compArrSize = 3;
    char compareArr[] ="ynq";
    
    std::cout << "New game? (y/n):" <<std::endl;;
    std::cin >> userInput;
    userInput = std::tolower(userInput);

    bool validInput = isValid <char> (userInput, compareArr, compArrSize);
    while (!validInput)
    {
        if (cout < 3)
        {        
            std::cout << userInput << " is not a valid option, please try again." << std::endl;
            std::cout << "New game? (y/n):" <<std::endl;
            std::cin >> userInput;
            userInput = std::tolower(userInput);
            validInput = isValid <char> (userInput, compareArr, compArrSize);
        } else
        {
            std::cout << "Try again later." << std::endl;
            userInput = 'q';
        }
    }
    return userInput;     
}

int main()
{
    //TODO: Step 1 - Ask user if they would like to start a new game
    char userInput = getUserCommand();

    //TODO: Step 2 - Loop until user exits game
    //TODO: Step 3 - Start game --> use Game class
    //TODO: Step 4 - Initial roll, 5 dice (Randomize 5 values) --> Use Die/Dice class
    //TODO: Step 5 - Display potential score based on dice rolls for each open category
    //TODO: Setp 6 - User may select a category to score in, begin new round with category locked (Return to Step 4 w/ 1 fewer categories)
    //TODO: Step 7 - User may select (or unselect) 0 to 5 dice to lock in for next round
    //TODO: Step 8 - Repeat step 4 (max 2 times) with unlocked dice 
    //TODO: Step 9 - Display final score
    //TODO: Step 10 - Ask user to play again
    //TODO              if yes, clear score and selected categories, repeat step 3 (or 4)
    //TODO:             if no, exit game
}