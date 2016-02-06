#include <iostream>
#include <vector>
#include "Fraction.h"
#include "Primes.h"

using namespace std;

int main() {
    Fraction f1(2, 3);
    Fraction f2(3, 5);
    Fraction f3 = f1 + f2;
    cout << "19/15 = " << f3 << endl;

    Fraction f4 = f2 - f1;
    cout << "-1/15 = " << f4 << endl;

    Fraction f5 = f1 * f2;
    cout << "2/5 = " << f5 << endl;

    Fraction f6 = f1 / f2;
    cout << "10/9 = " << f6 << endl;

    Fraction f7(1, 3);
    Fraction f8(4, 12);
    cout << "1/3 == 4/12: " << (f7 == f8 ? "yes" : "no") << endl;

    cout << "2/3 != 3/5: " << (f1 != f2 ? "yes" : "no") << endl;

    cout << "2/3 > 3/5: " << (f1 > f2 ? "yes" : "no") << endl;

    cout << "3/5 < 2/3: " << (f2 < f1 ? "yes" : "no") << endl;

    cout << "2/3 = " << (double)f1 << endl;

    cout << "Type your own fraction: ";
    Fraction f9;
    cin >> f9;
    cout << "Your fraction is " << f9 << "." << endl;

    return 0;
}