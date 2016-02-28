#include <iostream>
#include "PriorityQueue.h"

using namespace std;

int main() {

    PriorityQueue<int> queue{[](int a, int b)->int{return a - b;}};

    queue += new int(1);
    queue += new int(19);
    queue += new int(2);
    queue += new int(25);
    queue += new int(100);
    queue += new int(17);
    queue += new int(36);
    queue += new int(3);
    queue += new int(7);

    cout << queue << endl;

    int* top = queue.remove();

    cout << "Removed: " << *top << endl;

    cout << queue << endl;
}