#include "Dice.hpp"

void Dice::roll()
{
    for (int i = 0; i < HAND_SIZE; i++)
    {
        hand[i].roll();
    }
}