#pragma once

#include "Dice.hpp"

class Scorecard
{
private:
    static const int numOfCategories = 13;
    enum categories {Aces, Twos, Threes, Fours, Fives, Sixes, ThreeOfAKind, 
            FoursOfAKind, FullHouse, SmallStraight, LargeStraight, Yahtzee, Chance};

    
    const int fullHouse = 25;
    const int smStraight = 30;
    const int lgStraight = 40;
    const int yahtzee = 50;

    int score [2] [numOfCategories];     // First row contains scores, second row contains binary lock values
public:
    enum lock {Open, Closed};
    enum scoreRow {Score, Lock};
    // TODO: Reset scores
    void reset();
    // TODO: Display scoreboard
    // TODO:    Scoreboard based on roll
    // TODO:    Current scoreboard
    //      TODO:   Calculate Score per Category
    int sumDice(Dice& hand, int sumOn);
    int sumDice(Dice& hand);

    bool numPairs(Dice& hand, int numUnique, int pairNum); // TODO: Tie TOAK, FOAK, and FullHouse together
    
    bool isThreeOfAKind (Dice& hand) {return numPairs(hand, 3, 1);}
    bool isFourOfAKind (Dice& hand) {return numPairs(hand, 2, 1);}
    bool isFullHouse (Dice& hand) {return numPairs(hand, 2, 2);}
    bool isYahtzee (Dice& hand) {return numPairs(hand, 1, 1);}
    
    bool isSmStraight (Dice& hand);
    bool isLgStraight (Dice& hand);
    
    void calScore (Dice& hand);
    bool setScore (int Category);
    int scoreTotal();
    //      TODO:   Display Score in Scoreboard
    std::string getStringScore(categories cat, lock l);
    void displayScoreCard(lock l);

    // TODO:    Final (or current total) Score
    int getTotalScore();
};

