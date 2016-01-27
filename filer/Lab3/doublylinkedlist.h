#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "doublylinkednode.h"
class DoublyLinkedList
{
    public:
    /* Initialize values as needed */
        DoublyLinkedList();
    /* Remove the first element in the list
     * and return a pointer to the element */
        DoublyLinkedNode* removeFirst();
    /* Remove the last element in the list
     * and return a pointer to the element */
        DoublyLinkedNode* removeLast();
    /* Return a pointer to the first occurrence of the given
     * value in the list */
        DoublyLinkedNode* find( int val ) const;
    /* Remove the first occurrence of the given value in the list
     * and return a pointer to the element */
        DoublyLinkedNode* remove( int val );
    /* Add a node with the given value to the end of the list */
        void add( int val );
    /* return a pointer to the first node in the list */
        DoublyLinkedNode* first() const;
    /* Return a pointer to the last node in the list */
        DoublyLinkedNode* last() const;
    /* Return true if the given value is found in the list,
     * false otherwise */
        bool contains( int val ) const;
    /* Return true if the list is empty, false otherwise */
        bool isEmpty() const;
    /* Return the number of elements in the list */
        int size() const;
    private:
        DoublyLinkedNode *head;
        int numberOfElements;
};
#endif // DOUBLYLINKEDLIST_H