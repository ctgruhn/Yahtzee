#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>

class Die
{
private:
    int val;
public:
    const int getVal() {return val;}
    void setVal (int v){val = v;}
    void roll(){ val = rand() % 6 + 1;};
    
    friend bool operator<(Die const &die1, Die const &die2);
};


class Dice
{
private:
    static const int HAND_SIZE = 5;
    Die hand[HAND_SIZE];
public:
    Dice(){ srand(time(0)); }
    void roll();
    int getSize() { return HAND_SIZE;}
    int getDice(int die) {return hand[die].getVal();}
    
    void sort();
    
    void printHand();
    void setHand(int die1, int die2, int die3, int die4, int die5);
};
