#include <cstdlib>
#include <ctime>
#include <random>

mt19937 mt_rand(time(0));

void rollDice(int &die1, int &die2)
{
    die1 = (mt_rand() % 6);
    die2 = (mt_rand() % 6);
}
