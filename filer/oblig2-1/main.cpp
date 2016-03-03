#include <iostream>
#include "DoublyLinkedList.h"
#include "SortedDoublyLinkedList.h"

using namespace std;

int main() {

    DoublyLinkedList<int>* list = new SortedDoublyLinkedList<int>();
    list->add(new int(5));
    list->add(new int(3));
    list->add(new int(4));
    cout << *list->removeFirst()->getData() << endl;
    cout << *list->removeFirst()->getData() << endl;
    cout << *list->removeFirst()->getData() << endl;

}