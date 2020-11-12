#include "Dice.hpp"

bool operator<(Die const &die1, Die const &die2)
{
    return die1.val < die2.val;
}


void Dice::roll()
{
    for (int i = 0; i < HAND_SIZE; i++)
    {
        hand[i].roll();
    }
}

void Dice::printHand()
{
    for (int i = 0; i < HAND_SIZE; i++)
    {
        std::cout << "Die-" << i + 1 << " = " << hand[i].getVal() << "\t";
    }
    std::cout<<std::endl;
}

void Dice::setHand(int die1, int die2, int die3, int die4, int die5)
{
    hand[0].setVal(die1);
    hand[1].setVal(die2);
    hand[2].setVal(die3);
    hand[3].setVal(die4);
    hand[4].setVal(die5);
}

void Dice::sort()
{
    std::sort(hand, (hand + HAND_SIZE));
}
