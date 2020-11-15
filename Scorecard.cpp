#include "Scorecard.hpp"
#include <iomanip>

void Scorecard::reset()
{
    for (int i = 0; i < numOfCategories; i++)
    {
        score[0][i] = 0;        // Set score in each category to 0
        score[1][i] = 0;        // Set lock value to 0
    }
}

int Scorecard::getTotalScore()
{
    int sum = 0;
    for (int i = 0; i < numOfCategories; i++)
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

int Scorecard::scoreTotal()
{
    int sum = 0;
    for(int index = 0; index < numOfCategories; index++)
    {
        if(score[0][index] == Closed)
            sum += score[1][index];
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
            if(score[Lock][catIndex] == Open)
                score[Score][catIndex] = sumDice(hand, catIndex + 1);
        }
        if(score[Lock][Chance] == Open)
            score[Score][Chance] = sum;
        if (score[Lock][ThreeOfAKind] == Open)
        {
            if(isThreeOfAKind(hand))
                score[Score][ThreeOfAKind] = sum;
            else
                score[Score][ThreeOfAKind] = 0;
        }
        if(score[Lock][FoursOfAKind] == Open)
        {
            if(isFourOfAKind(hand))
                score[Score][FoursOfAKind] = sum;
            else
                score[Score][FoursOfAKind] = 0;
        }
        if(score[Lock][FullHouse] == Open)
        {
            if(isFullHouse(hand))
               score[Score][FullHouse] = fullHouse;
            else
               score[Score][FullHouse] = 0;
        }
        if(isSmStraight(hand) && score[Lock][SmallStraight] == Open)
            score[1][SmallStraight] = smStraight;
        if(isLgStraight(hand) && score[Lock][LargeStraight] == Open)
            score[Score][LargeStraight] = lgStraight;
        if(score[Lock][Yahtzee] == Open)
        {
            if(isYahtzee(hand))
               score[Score][Yahtzee] = yahtzee;
            else
               score[Score][Yahtzee] = 0;

        }
        else if (score[Lock][Yahtzee] == Open)
            score[Score][Yahtzee] = 0;
    }

bool Scorecard::setScore(int Category)
{
  if(score[Lock][Category - 1] > 0)
  {

      std::cout << "\nThat Category has already been selected." << std::endl;
      return false;
  }
  else
  {
      score[Lock][Category - 1] = 1;
      return true;
  }
}


std::string Scorecard::getStringScore(categories cat, lock l)
{
    if (score[Lock][cat] == l) {
        return std::to_string(score[Score][cat]);
    }
    else
        return "X";
}

void Scorecard::displayCategories()
{
    std::cout << "\nCategory Numbers:\n"
              << std::left << std::setw(15) << "\t1. Aces" << std::setw(15) << "4. Fours" << std::setw(25) << "7. Chance" << std::setw(20) << "10. Full House" << "13. Yahtzee" << "\n"
              << std::setw(15) << "\t2. Twos" << std::setw(15) << "5. Fives" << std::setw(25) << "8. Three of a Kind" << "11. Sm Straight" << "\n"
    << std::setw(15) << "\t3. Threes" << std::setw(15) << "6. Sixes" << std::setw(25) << "9. Four of a Kind" << "12. Lg Straight" << "\n" << std::endl;

}


void Scorecard::displayScoreCard(lock l)
{
  std::cout << std::right
            << "==============================================================================\n"
            << "|    | Category | Category | Category | Category | Category | Category |     |\n"
            << "|    |     1    |     2    |     3    |     4    |     5    |     6    |     |\n"
            << "|    |----------|----------|----------|----------|----------|----------|     |\n"
            << "|    |   Aces   |   Twos   |  Threes  |   Fours  |   Fives  |   Sixes  |     |\n"
            << "|    |----------|----------|----------|----------|----------|----------|     |\n"
            << "|    |" << std::setw(6) << getStringScore(Aces, l) << std::setw(5) << "|"
                   << std::setw(6) << getStringScore(Twos, l) << std::setw(5) << "|"
                   << std::setw(6) << getStringScore(Threes, l) << std::setw(5) << "|"
                   << std::setw(6) << getStringScore(Fours, l) << std::setw(5) << "|"
                   << std::setw(6) << getStringScore(Fives, l) << std::setw(5) << "|"
                   << std::setw(6) << getStringScore(Sixes, l) << std::setw(5) << "|" << "     |\n"
    << "==============================================================================\n"
    << "| Category | Category | Category | Category | Category | Category | Category |\n"
    << "|     7    |     8    |     9    |    10    |    11    |    12    |    13    |\n"
    << "|----------|----------|----------|----------|----------|----------|----------|\n"
    << "|          | Three of |  Four of |          |   Small  |  Large   |          |\n"
    << "|  Chance  |  a kind  |  a kind  |Full House| Straight | Straight |  Yahtzee |\n"
    << "|----------|----------|----------|----------|----------|----------|----------|\n"
    << "|" << std::setw(6) << getStringScore(Chance, l) << std::setw(5) << "|"
           << std::setw(6) << getStringScore(ThreeOfAKind, l) << std::setw(5) << "|"
           << std::setw(6) << getStringScore(FoursOfAKind, l) << std::setw(5) << "|"
           << std::setw(6) << getStringScore(FullHouse, l) << std::setw(5) << "|"
           << std::setw(6) << getStringScore(SmallStraight, l) << std::setw(5) << "|"
    << std::setw(6) << getStringScore(LargeStraight, l) << std::setw(5) << "|"
           << std::setw(6) << getStringScore(Yahtzee, l) << std::setw(5) << "|" << "\n"
    << "==============================================================================\n"
    << "|" << std::setw(38) << "TOTAL SCORE:" << std::setw(10) << scoreTotal() << std::setw(30) << "|\n"
    << "==============================================================================\n"
    << std::endl;

}
