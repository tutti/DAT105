#include <iostream>
#include "SortedDoublyLinkedList.h"

using namespace std;

int main() {

    /*
    int* testint = new int(5);
    DoublyLinkedNode<int>* test = new DoublyLinkedNode<int>(testint);

    int* testint2 = test->getData();

    cout << *testint2 << endl;
    */

    DoublyLinkedList<int>* list = new SortedDoublyLinkedList<int>();
    list->add(new int(5));
    list->add(new int(3));
    list->add(new int(4));
    cout << *list->removeFirst()->getData() << endl;
    cout << *list->removeFirst()->getData() << endl;
    cout << *list->removeFirst()->getData() << endl;

}