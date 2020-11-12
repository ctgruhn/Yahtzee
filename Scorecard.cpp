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

int Scorecard::sumDice(Dice& hand)
{
  int sum = 0;
    for(int i = 0; i < hand.getSize(); i++)
  {
      sum += hand.getDice(i);
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


bool Scorecard::isSmStraight(Dice &hand)
{
    int curVal = hand.getDice(0);
    int index = 1;
    int skippedIndex = 0; // Noncontiguous indexes skipped. 1 Skip allowed.
    bool isStraight = true;
    while (index < hand.getSize() && skippedIndex < 2)
    {

      if( hand.getDice(index) != ++curVal)
      {
        skippedIndex++;
        curVal = hand.getDice(index);
      }
        index++;
    }
    isStraight = skippedIndex < 2;
    return isStraight;
}

bool Scorecard::isLgStraight(Dice &hand)
{
    int curVal = hand.getDice(0);
    int index = 1;
    bool isStraight = true;
    while (index < hand.getSize() && isStraight)
    {
        isStraight = hand.getDice(index) == ++curVal;
        index++;
    }
    return isStraight;
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

void Scorecard::calScore(Dice& hand)
{
        int sum = sumDice(hand);
        // For all categories not already selected, sum on
        for(int catIndex = Aces; catIndex < ThreeOfAKind; catIndex++)
        {
            if(score[0][catIndex] == Open)
                score[1][catIndex] = sumDice(hand, catIndex + 1);
        }
        if(score[0][Chance] == Open)
            score[1][Chance] = sum;
        if (score[0][ThreeOfAKind] == Open)
        {
            if(isThreeOfAKind(hand))
                score[1][ThreeOfAKind] = sum;
            else
                score[1][ThreeOfAKind] = 0;
        }
        if(score[0][FoursOfAKind] == Open)
        {
            if(isFourOfAKind(hand))
                score[1][FoursOfAKind] = sum;
            else
                score[1][FoursOfAKind] = 0;
        }
        if(score[0][FullHouse] == Open)
        {
            if(isFullHouse(hand))
               score[1][FullHouse] = fullHouse;
            else
               score[1][FullHouse] = 0;
        }
        if(isSmStraight(hand) && score[0][SmallStraight] == Open)
            score[1][SmallStraight] = smStraight;
        if(isLgStraight(hand) && score[0][LargeStraight] == Open)
            score[1][LargeStraight] = lgStraight;
        if(score[0][Yahtzee] == Open)
        {
            if(isYahtzee(hand))
               score[1][Yahtzee] = yahtzee;
            else
               score[1][Yahtzee] = 0;

        }
        else if (score[0][Yahtzee] == Open)
            score[1][Yahtzee] = 0;
    }

bool Scorecard::setScore(int Category)
{
  if(score[0][Category - 1] > 0)
  {

      std::cout << "\nThat Category has already been selected." << std::endl;
      return false;
  }
  else
  {
      score[0][Category - 1] = 1;
      return true;
  }
}
