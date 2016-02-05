#include <iostream>
#include "doublylinkedlist.h"

using namespace std;

int main(int argc, char *argv[])
{
    DoublyLinkedList list = DoublyLinkedList{};

    cout << "List is empty before adding anything: " << list.isEmpty() << endl;
    cout << "Now adding 2, 3, 5, 7 and 11." << endl;

    list.add(2);
    list.add(3);
    list.add(5);
    list.add(7);
    list.add(11);

    cout << "List is empty after adding elements: " << list.isEmpty() << endl;
    cout << "Now removing 4, 5 and 6." << endl;

    delete list.remove(4);
    delete list.remove(5);
    delete list.remove(6);

    cout << "First element: " << list.first()->getData() << endl;
    cout << "Last element: " << list.last()->getData() << endl;
    cout << "List size: " << list.size() << endl;

    for (int i = 7; i <= 9; ++i) {
        cout << "List contains " << i << ": " << list.contains(i) << endl;
    }

    DoublyLinkedNode* last = list.removeLast();
    DoublyLinkedNode* first = list.removeFirst();

    cout << "Removing last element: " << last->getData() << endl;
    cout << "Removing first element: " << first->getData() << endl;
    cout << "List size: " << list.size() << endl;

    delete last;
    delete first;

    cout << "Removing remaining elements from list:";

    int size = list.size();

    for (int i = 0; i < size; ++i) {
        first = list.removeFirst();
        cout << " " << first->getData();
        delete first;
    }

    cout << endl;
}
