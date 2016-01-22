#include <iostream>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void oppg5(int numbers[])
{
    int i, j;
    for (i = (sizeof(numbers) - 1); i >= 0; i--) {
        for (j = 1; j <= i; j++) {
            if (numbers[j-1] > numbers[j])
                swap(numbers[j-1], numbers[j]);
        }
    }
}
