#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "DoublyLinkedListADT.h"
#include "DoublyLinkedNode.h"

using namespace std;

template<class T>
class DoublyLinkedList : public DoublyLinkedListADT<T> {
    public:
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
            elementCount = 0;
        }

        ~DoublyLinkedList() {
            DoublyLinkedNode<T>* node = head;
            while (head != nullptr) {
                node = head->getNext();
                delete head;
                head = node;
            }
        }

        virtual void add(T* t) {
            DoublyLinkedNode<T>* node = new DoublyLinkedNode<T>(t);

            if (head == nullptr) {
                head = node;
                tail = node;
                ++elementCount;
                return;
            }

            node->setPrevious(tail);
            tail->setNext(node);
            tail = node;
            ++elementCount;
        }

        DoublyLinkedNode<T>* removeFirst() {
            // If there are no elements, return nothing.
            if (head == nullptr) {
                return nullptr;
            }

            // If there's exactly one element, it's both head and tail, so
            // clear both and return that.
            if (head == tail) {
                DoublyLinkedNode<T>* elmt = head;
                head = nullptr;
                tail = nullptr;
                --elementCount;
                return elmt;
            }

            // If there are two or more elements, this won't affect the tail.

            // Get the current head
            DoublyLinkedNode<T>* first = head;
            // Move the head along to the next element
            head = first->getNext();
            // Disconnect the old head from the new head
            head->setPrevious(nullptr);
            first->setNext(nullptr);

            // Update the element count and return the element
            --elementCount;
            return first;
        }

        DoublyLinkedNode<T>* removeLast() {
            // If there are no elements, return nothing.
            if (tail == nullptr) {
                return nullptr;
            }

            // If there's exactly one element, it's both head and tail, so
            // clear both and return that.
            if (head == tail) {
                DoublyLinkedNode<T>* elmt = head;
                head = nullptr;
                tail = nullptr;
                --elementCount;
                return elmt;
            }

            // If there are two or more elements, this won't affect the head.

            // Get the current tail
            DoublyLinkedNode<T>* last = tail;
            // Move the tail along to the next element
            tail = last->getPrevious();
            // Disconnect the old tail from the new tail
            tail->setNext(nullptr);
            last->setPrevious(nullptr);

            // Update the element count and return the element
            --elementCount;
            return last;
        }

        DoublyLinkedNode<T>* find(T* t) const {
            if (head == nullptr) {
                return nullptr;
            }
            DoublyLinkedNode<T>* check = head;

            while (check != nullptr && check->getData() != t) {
                check = check->getNext();
            }

            return check;
        }

        DoublyLinkedNode<T>* remove(T* t) {
            // Look for the node first
            DoublyLinkedNode<T>* found = this->find(t);

            // If it wasn't found, do nothing and return nothing.
            if (found == nullptr) {
                return nullptr;
            }

            // If the found node is either the head or the tail,
            // special logic is needed, which already exists as methods.
            if (found == head) {
                return this->removeFirst();
            }
            if (found == tail) {
                return this->removeLast();
            }

            // Otherwise, disconnect the node from the list...
            DoublyLinkedNode<T>* previous = found->getPrevious();
            DoublyLinkedNode<T>* next = found->getNext();
            previous->setNext(next);
            next->setPrevious(previous);
            found->setPrevious(nullptr);
            found->setNext(nullptr);

            // ...and return it.
            --elementCount;
            return found;
        }

        DoublyLinkedNode<T>* first() const {
            return head;
        }

        DoublyLinkedNode<T>* last() const {
            return tail;
        }

        bool contains(T* t) const {
            DoublyLinkedNode<T>* found = this->find(t);
            return (found != nullptr);
        }

        bool isEmpty() const {
            return (elementCount == 0);
        }

        int size() const {
            return elementCount;
        }
    protected:
        DoublyLinkedNode<T>* head;
        DoublyLinkedNode<T>* tail;
        int elementCount;
};

#endif