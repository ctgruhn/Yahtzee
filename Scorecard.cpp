#include "Scorecard.hpp"

void Scorecard::reset()
{
    for (int i = 0; i < catSize; i++)
    {
        score[0][i] = 0;        // Set score in each category to 0
        score[1][i] = 0;        // Set lock value to 0
    }
}

int Scorecard::getTotalScore()
{
    int sum = 0;
    for (int i = 0; i < catSize; i++)
    {
        if (score[Lock][i] == Open)
            sum += score[Score][i];
    }
    return sum;
}

int Scorecard::sumDice(Dice& hand, int sumOn)
{
  int sum = 0;
    for(int i = 0; i < hand.getSize(); i++)
  {
    if(hand.getDice(i) == sumOn)
      sum += hand.getDice(i);
  }
  return sum;
}

bool Scorecard::numPairs(Dice& hand, int numUnique, int pairNum)
{
    int pairs = 0;
    int unique = hand.getSize();
    int curVal = hand.getDice(0);
    int prevVal = -1;

    for (int i = 1; i < hand.getSize(); i++)
    {
        if (hand.getDice(i) == curVal)
        {
            if(curVal != prevVal)
                pairs++;
            unique --;
            prevVal = curVal;
        }
        else
        {
            curVal = hand.getDice(i);
        }

    }
    return (numUnique == unique && pairNum == pairs);
}

