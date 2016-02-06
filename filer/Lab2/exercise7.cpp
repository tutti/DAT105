#include <iostream>
#include "rolldice_pnt.h"

using namespace std;

// Pengene du starter med
const int START_MONEY = 1000;

void oppg7()
{
    // Gi spilleren nok penger til å starte med
    unsigned int money = START_MONEY;
    // Variabler for verdier som brukes inne i løkken
    unsigned int bet;
    int die1, die2;
    char in;

    // Loopen kontrolleres av break-setninger
    while(true) {
        // Skriver ut pengene spilleren har
        printf("Du har %i kroner å vedde med.\n", money);

        // Spør spilleren om en innsats
        do {
            cout << "Din innsats: ";
            cin >> bet;
            if (bet > money) {
                cout << "Du har ikke så mye penger." << endl;
            }
        } while (bet > money);

        // Rull terningene og skriv ut resultatet
        rollDice(die1, die2);
        printf("Terningkast: %i, %i\n", die1, die2);

        // Sjekk om spilleren vant
        if (die1 + die2 == 7 || die1 + die2 == 11) {
            cout << "Du vant!" << endl;
            money += bet;
        } else {
            cout << "Du tapte!" << endl;
            money -= bet;

            // Hvis spilleren er tom for penger, er spillet over.
            if (money <= 0) {
                cout << "Du har ingen penger igjen. Spillet er over." << endl;
                break;
            }
        }

        // Spør spilleren om denne fortsatt vil spille.
        do {
            cout << "Vil du fortsatt spille? y/n: ";
            cin >> in;
        } while (in != 'y' && in != 'n');
        if (in == 'n') {
            break;
        }
    }
}
