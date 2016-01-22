#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;
mt19937 mt_rand(time(0));

void rollDice(int &die1, int &die2)
{
    unsigned int rand1 = mt_rand();
    unsigned int rand2 = mt_rand();
    die1 = (rand1 % 6) + 1;
    die2 = (rand2 % 6) + 1;
}
