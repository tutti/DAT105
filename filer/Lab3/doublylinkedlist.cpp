#include "doublylinkedlist.h"

using namespace std;

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    numberOfElements = 0;
}

DoublyLinkedNode* DoublyLinkedList::removeFirst() {
    if (head == nullptr) {
        return nullptr;
    }

    DoublyLinkedNode* elem = head;
    head = elem->getNext();
    if (head != nullptr) {
        head->setPrevious(nullptr);
    }
    elem->setNext(nullptr);
    --numberOfElements;
    return elem;
}

DoublyLinkedNode* DoublyLinkedList::removeLast() {
    if (head == nullptr) {
        return nullptr;
    }

    DoublyLinkedNode* last = this->last();

    if (head == last) {
        head = nullptr;
        --numberOfElements;
        return last;
    }

    if (last->getPrevious() != nullptr) {
        last->getPrevious()->setNext(nullptr);
        last->setPrevious(nullptr);
    }

    --numberOfElements;
    return last;
}

DoublyLinkedNode* DoublyLinkedList::find(int val) const {
    DoublyLinkedNode* check = head;
    while (check != nullptr && check->getData() != val) {
        check = check->getNext();
    }
    return check;
}

DoublyLinkedNode* DoublyLinkedList::remove(int val) {
    DoublyLinkedNode* elem = find(val);
    if (elem == nullptr) {
        return nullptr;
    }

    DoublyLinkedNode* next = elem->getNext();
    DoublyLinkedNode* previous = elem->getPrevious();
    if (previous != nullptr) {
        previous->setNext(next);
    }
    if (next != nullptr) {
        next->setPrevious(previous);
    }
    elem->setNext(nullptr);
    elem->setPrevious(nullptr);

    if (elem == head) {
        head = next;
    }

    --numberOfElements;
    return elem;
}

void DoublyLinkedList::add(int val) {
    DoublyLinkedNode* node = new DoublyLinkedNode(val, last(), nullptr);
    if (head == nullptr) {
        head = node;
    } else {
        DoublyLinkedNode* last = this->last();
        last->setNext(node);
    }
    ++numberOfElements;
}

DoublyLinkedNode* DoublyLinkedList::first() const {
    return head;
}

DoublyLinkedNode* DoublyLinkedList::last() const {
    if (head == nullptr) {
        return nullptr;
    }

    DoublyLinkedNode* last = head;
    while (last->getNext() != nullptr) {
        last = last->getNext();
    }

    return last;
}

bool DoublyLinkedList::contains(int val) const {
    return (find(val) != nullptr);
}

bool DoublyLinkedList::isEmpty() const {
    return (head == nullptr);
}

int DoublyLinkedList::size() const {
    return numberOfElements;
}