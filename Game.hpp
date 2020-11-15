#pragma once //Game.hpp

#include "Scorecard.hpp"

class Game
{
private:
    bool playing = true;
    int MAX_ROUNDS = 13;
    // TODO: hand variable -- from Dice class
    Dice hand;
    // TODO: scoreboard variable -- from Scoreboard class
    Scorecard score;
public:
    // TODO: play function -- function runs general game
    
    bool start();
    void play();
    bool isPlaying(){ return playing;}
    int getUserInput(std::string input);
    void getInstructions();
    void continuePlaying(std::string input);
    int intValidation(std::string input);
    bool stringValidation(std::string input);

    



    // TODO: exit function

    // TODO: Roll dice
    // TODO:    Select dice (to keep / to reroll)
    // TODO: Choose category
    // TODO: Show score:
    // TODO:    Potential category score to choose from (from open categories)
    // TODO:    Current Score (from categories already scored)
    // TODO:    Final Score
};
