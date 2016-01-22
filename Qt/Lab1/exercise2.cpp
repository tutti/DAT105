#include <iostream>

using namespace std;

const int ANTALL_TALL_A = 3;
const int ANTALL_TALL_C = 7;

void oppg2() {
    // a)
    cout << "Skriv inn " << ANTALL_TALL_A << " tall:" << endl;
    int hoyeste = 0;
    int tall;
    for (int i = 0; i < ANTALL_TALL_A; ++i) {
        cin >> tall;
        if (tall > hoyeste) {
            hoyeste = tall;
        }
    }
    cout << "Høyeste tall: " << hoyeste << endl;

    // b)
    cout << "Skriv inn grensene for utskrift:" << endl;
    int nedre, ovre;
    cin >> nedre;
    cin >> ovre;
    cout << "Oddetall mellom " << nedre << " og " << ovre << ":" << endl;
    nedre -= (nedre%2) - 1;
    for (int i = nedre; i <= ovre; i+=2) {
        cout << i << endl;
    }

    // c
    cout << "Skriv inn " << ANTALL_TALL_C << " tall:" << endl;
    int talliste[ANTALL_TALL_C];
    for (int i = 0; i < ANTALL_TALL_C; ++i) {
        cin >> talliste[i];
    }
    int min = talliste[0];
    int max = talliste[0];
    int sum = talliste[0];
    for (int i = 1; i < ANTALL_TALL_C; ++i) {
        if (talliste[i] < min) {
            min = talliste[i];
        }
        if (talliste[i] > max) {
            max = talliste[i];
        }
        sum += talliste[i];
    }
    float avg = (float)sum / (float)ANTALL_TALL_C;
    cout << "Minste tall: " << min << endl;
    cout << "Største tall: " << max << endl;
    cout << "Gjennomsnitt: " << avg << endl;
}
