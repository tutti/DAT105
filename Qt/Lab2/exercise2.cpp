#include <iostream>

using namespace std;

void oppg2()
{
    cout << "Skriv inn et tall: ";
    int n;
    cin >> n;

    int t = 1;
    for (int i = 1; i <= n; ++i) {
        t *= i;
    }

    cout << n << "! = " << t << endl;

    cout << endl;

    n = 2;
    t = 0;
    int nt = 1;

    while (nt > t) {
        t = nt;
        cout << n;
        nt *= n++;
        cout << "! = " << nt << endl;
    }
}
