#include "doublylinkedlist.h"

using namespace std;

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    numberOfElements = 0;
}

DoublyLinkedNode* DoublyLinkedList::removeFirst() {
    // If there's nothing, then there's nothing to remove.
    if (head == nullptr) {
        return nullptr;
    }

    // Pop the head, and if there's a second element, make it head.
    DoublyLinkedNode* elem = head;
    head = elem->getNext();
    if (head != nullptr) {
        head->setPrevious(nullptr);
    }

    // Dissociate the removed node from the list
    elem->setNext(nullptr);

    // Reduce the element count and return.
    --numberOfElements;
    return elem;
}

DoublyLinkedNode* DoublyLinkedList::removeLast() {
    // If there's nothing, then there's nothing to remove.
    if (head == nullptr) {
        return nullptr;
    }

    // Find the last node in the list
    DoublyLinkedNode* last = this->last();

    // If there's only one node, then remove it and return it.
    if (head == last) {
        head = nullptr;
        --numberOfElements;
        return last;
    }

    // Otherwise, dissociate the last node and the list, and return the node.
    if (last->getPrevious() != nullptr) {
        last->getPrevious()->setNext(nullptr);
        last->setPrevious(nullptr);
    }

    --numberOfElements;
    return last;
}

DoublyLinkedNode* DoublyLinkedList::find(int val) const {
    // Start at the head
    DoublyLinkedNode* check = head;
    // Keep looking for the node
    while (check != nullptr && check->getData() != val) {
        check = check->getNext();
    }
    // check will be the node with the node if found, nullptr if not.
    return check;
}

DoublyLinkedNode* DoublyLinkedList::remove(int val) {
    // Find the node with the value
    DoublyLinkedNode* elem = find(val);
    // If there wasn't one, return nothing.
    if (elem == nullptr) {
        return nullptr;
    }

    // Get the nodes to the left and right of this one
    DoublyLinkedNode* next = elem->getNext();
    DoublyLinkedNode* previous = elem->getPrevious();

    // Point them to each other (if they exist)
    if (previous != nullptr) {
        previous->setNext(next);
    }
    if (next != nullptr) {
        next->setPrevious(previous);
    }

    // Dissociate this node from the list
    elem->setNext(nullptr);
    elem->setPrevious(nullptr);

    // If the head was removed, change the head.
    if (elem == head) {
        head = next;
    }

    // Update the element count and return
    --numberOfElements;
    return elem;
}

void DoublyLinkedList::add(int val) {
    // Create the node (getting last() as the previous ref)
    DoublyLinkedNode* node = new DoublyLinkedNode(val, last(), nullptr);

    if (head == nullptr) {
        // If there's no head, this is now the head
        head = node;
    } else {
        // If there's a head, find the last node and append this node.
        DoublyLinkedNode* last = this->last();
        last->setNext(node);
    }
    ++numberOfElements;
}

DoublyLinkedNode* DoublyLinkedList::first() const {
    // Returns the head, if it exists.
    return head;
}

DoublyLinkedNode* DoublyLinkedList::last() const {
    // If there's no head, there's no tail.
    if (head == nullptr) {
        return nullptr;
    }

    // Start at the head, and keep working backwards.
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