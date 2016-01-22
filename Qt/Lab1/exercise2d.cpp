#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

void oppg2d() {
    mt19937 mt_rand(time(0));

    unsigned int tall = mt_rand();
    unsigned int max = mt19937::max();

    cout << "Gjett et tall mellom 0 og " << max << ":" << endl;

    unsigned int gjett = -1;
    while (gjett != tall) {
        cin >> gjett;
        if (gjett < tall) {
            cout << "Feil, tallet er større." << endl;
        } else if (gjett > tall) {
            cout << "Feil, tallet er mindre." << endl;
        } else {
            cout << "Riktig!" << endl;
        }
    }
}
