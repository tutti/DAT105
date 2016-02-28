#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

int main() {

    /*
    int* testint = new int(5);
    DoublyLinkedNode<int>* test = new DoublyLinkedNode<int>(testint);

    int* testint2 = test->getData();

    cout << *testint2 << endl;
    */

    DoublyLinkedList<int>* list = new DoublyLinkedList<int>();
    list->add(new int(5));
    list->add(new int(3));
    list->add(new int(4));
    cout << *list->removeFirst()->getData() << endl;
    cout << *list->removeFirst()->getData() << endl;
    cout << *list->removeFirst()->getData() << endl;

}