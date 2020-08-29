#pragma once Scorecard.hpp

class Scorecard
{
private:
    int catSize = 13;
    enum categories {Aces, Twos, Threes, Fours, Fives, Sixes, ThreeOfAKind, 
            FoursOfAKind, FullHouse, SmallStraight, LargeStraight, Yahtzee, Chance};
    enum lock {Open, Closed};
    enum scoreRow {Score, Lock};
    
    int score [2] [13];     // First row contains scores, second row contains binary lock values
public:
    // TODO: Reset scores
    void reset();
    // TODO: Display scoreboard
    // TODO:    Scoreboard based on roll
    // TODO:    Current scoreboard
    //  TODO:
    // TODO:    Final (or current total) Score
    int getTotalScore();
};
