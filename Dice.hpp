#ifndef Dice_hpp
#define Dice_hpp

#include <iostream>
#include <stdlib.h>
#include <time.h>

class Die
{
private:
    int val;
public:
    const int getVal() {return val;}
    void roll(){ val = rand() % 6 + 1;};
};


class Dice
{
private:
    static const int HAND_SIZE = 5;
    Die hand[HAND_SIZE];
public:
    Dice(){ srand(time(0)); }  // Set seed for roll() rand function
    void roll();
    int getSize() { return HAND_SIZE;}
    void printHand() { for (int i = 0; i < HAND_SIZE; i++){ std::cout << hand[i].getVal() << std::endl;}}
};

#endif /* Dice_hpp */