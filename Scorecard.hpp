#pragma once

#include "Dice.hpp"

class Scorecard
{
private:
    int catSize = 13;
    enum categories {Aces, Twos, Threes, Fours, Fives, Sixes, ThreeOfAKind, 
            FoursOfAKind, FullHouse, SmallStraight, LargeStraight, Yahtzee, Chance};
    enum lock {Open, Closed};
    enum scoreRow {Score, Lock};
    
    const int fullHouse = 25;
    const int smStraight = 30;
    const int lgStraight = 40;
    const int yahtzee = 50;

    int score [2] [13];     // First row contains scores, second row contains binary lock values
public:
    // TODO: Reset scores
    void reset();
    // TODO: Display scoreboard
    // TODO:    Scoreboard based on roll
    // TODO:    Current scoreboard
    //      TODO:   Calculate Score per Category
    int sumDice(Dice& hand, int sumOn);
    bool numPairs(Dice& hand, int numUnique, int pairNum); // TODO: Tie TOAK, FOAK, and FullHouse together
    bool isThreeOfAKind (Dice& hand) {return numPairs(hand, 3, 1);}
    bool isFourOfAKind (Dice& hand) {return numPairs(hand, 2, 1);}
    bool isFullHouse (Dice& hand) {return numPairs(hand, 2, 2);}
    bool isYahtzee (Dice& hand) {return numPairs(hand, 1, 1);}
    //      TODO:   Display Score in Scoreboard
    // TODO:    Final (or current total) Score
    int getTotalScore();
};
