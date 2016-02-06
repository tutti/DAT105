#include <iostream>
#include <ctime>
#include <random>

// The implementation using & remains, but all the code below has changed to
// use the implementation using *.

using namespace std;

// Mersenne twister, because the standard random wasn't random enough.
mt19937 mt_rand(time(0));

void rollDice_r(int &die1, int &die2) {
    unsigned int rand1 = mt_rand();
    unsigned int rand2 = mt_rand();
    die1 = (rand1 % 6) + 1;
    die2 = (rand2 % 6) + 1;
}

void rollDice_p(int *die1, int *die2) {
    unsigned int rand1 = mt_rand();
    unsigned int rand2 = mt_rand();
    *die1 = (rand1 % 6) + 1;
    *die2 = (rand2 % 6) + 1;
}

int main(int argc, char *argv[])
{
    int money = 1000;
    int in;
    char c;
    int die1, die2;

    while (money > 0) {
        cout << "You have " << money << " to bet on your next game." << endl;
        cout << "Your bet: ";
        cin >> in;
        while (in > money || in < 1) {
            cout << "You need to bet a number between 1 and " << money << "." << endl;
            cout << "Your bet: ";
            cin >> in;
        }

        rollDice_p(&die1, &die2);

        cout << "Die 1: " << die1 << ", die 2: " << die2 << endl;

        if (die1 + die2 == 7 || die1 + die2 == 11) {
            cout << "You won!" << endl;
            money += in;
        } else {
            cout << "Sorry, you lost." << endl;
            money -= in;
        }

        if (money > 0) {
            cout << "Do you want to play more? [y/n] ";
            cin >> c;
            while (c != 'y' && c != 'n') {
                cout << "Invalid input. Do you want to play more? [y/n] ";
                cin >> c;
            }
            if (c == 'n') {
                money = 0;
            }
        } else {
            cout << "Game over." << endl;
        }
    }

    return 0;
}
