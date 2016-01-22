#include <iostream>

using namespace std;

void oppg1()
{
    char in;
    int t1, t2;

    while (true) {
        cout << "Skriv inn to tall eller |: ";
        cin >> in;
        if (in == '|') break;
        cin >> t1;
        cin >> t2;
        cout << "Dine tall: " << in << t1 << " " << t2 << endl;
    }
}

