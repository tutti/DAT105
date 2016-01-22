#include <iostream>

using namespace std;

void oppg1()
{
    cout << "Test av repetisjonssetning." << endl;
    cout << "***************************" << endl;

    for (int i = 1; i <= 10; ++i) {
        cout << "Dette er linje nr. ";
        cout << i;
        cout << endl;
        if (i%4 == 0) {
            cout << endl;
        }
    }
}
