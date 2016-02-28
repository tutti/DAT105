#ifndef SORTEDDOUBLYLINKEDLIST_H
#define SORTEDDOUBLYLINKEDLIST_H

#include "DoublyLinkedList.h"
#include "DoublyLinkedNode.h"

using namespace std;

template<class T>
class SortedDoublyLinkedList : public DoublyLinkedList<T> {
    public:
        using DoublyLinkedList<T>::DoublyLinkedList;

        void add(T* t) {
            DoublyLinkedNode<T>* node = new DoublyLinkedNode<T>(t);

            if (this->head == nullptr) {
                this->head = node;
                this->tail = node;
                ++this->elementCount;
                return;
            }

            if (*t < *this->head->getData()) {
                this->head->setPrevious(node);
                node->setNext(this->head);
                this->head = node;
                ++this->elementCount;
                return;
            }

            if (*t > *this->tail->getData()) {
                this->tail->setNext(node);
                node->setPrevious(this->tail);
                this->tail = node;
                ++this->elementCount;
                return;
            }

            DoublyLinkedNode<T>* greater = this->head;
            while (greater != nullptr && *greater->getData() < *t) {
                greater = greater->getNext();
            }

            DoublyLinkedNode<T>* lesser = greater->getPrevious();

            lesser->setNext(node);
            node->setPrevious(lesser);
            greater->setPrevious(node);
            node->setNext(greater);
            ++this->elementCount;
        }
};

#endif