#include "doublylinkednode.h"

using namespace std;

DoublyLinkedNode::DoublyLinkedNode() {
    data = 0;
    nextNode = nullptr;
    previousNode = nullptr;
}

DoublyLinkedNode::DoublyLinkedNode(int data, DoublyLinkedNode* previous, DoublyLinkedNode* next) {
    this->data = data;
    nextNode = next;
    previousNode = previous;
}

DoublyLinkedNode* DoublyLinkedNode::getNext() const {
    return nextNode;
}

DoublyLinkedNode* DoublyLinkedNode::getPrevious() const {
    return previousNode;
}

int DoublyLinkedNode::getData() const {
    return data;
}

void DoublyLinkedNode::setData(int newData) {
    data = newData;
}

void DoublyLinkedNode::setNext(DoublyLinkedNode* next) {
    nextNode = next;
}

void DoublyLinkedNode::setPrevious(DoublyLinkedNode* previous) {
    previousNode = previous;
}