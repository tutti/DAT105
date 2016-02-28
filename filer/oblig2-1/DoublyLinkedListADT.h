#ifndef DOUBLYLINKEDLISTADT_H
#define DOUBLYLINKEDLISTADT_H

#include "DoublyLinkedNode.h"

using namespace std;

template <class T>
class DoublyLinkedListADT
{
    public:
        virtual void add(T* t) = 0;
        virtual DoublyLinkedNode<T>* removeFirst() = 0;
        virtual DoublyLinkedNode<T>* removeLast() = 0;
        virtual DoublyLinkedNode<T>* find(T* t) const = 0;
        virtual DoublyLinkedNode<T>* remove(T* t) = 0;
        virtual DoublyLinkedNode<T>* first() const = 0;
        virtual DoublyLinkedNode<T>* last() const = 0;
        virtual bool contains(T* t) const = 0;
        virtual bool isEmpty() const = 0;
        virtual int size() const = 0;
};

#endif