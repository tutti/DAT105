#ifndef DOUBLYLINKEDNODE_H
#define DOUBLYLINKEDNODE_H
class DoublyLinkedNode
{
    public:
    /* Initialize values as needed */
        DoublyLinkedNode();
    /* Initialize a node with the given values */
        DoublyLinkedNode( int data, DoublyLinkedNode* previous, DoublyLinkedNode* next);
    /* Return a pointer to the next node in the list
     * Return NULL if the node is the last in the list */
        DoublyLinkedNode* getNext() const;
    /* Return a pointer to the previous node in the list
     * Return NULL if the node is the first in the list */
        DoublyLinkedNode* getPrevious() const;
    /* Return the data contained in the node */
        int getData() const;
    /* Set the data in the node */
        void setData(int newData);
    /* Set the next node */
        void setNext( DoublyLinkedNode* next);
    /* Set the previous node */
        void setPrevious( DoublyLinkedNode* previous);
    private:
        int data;
        DoublyLinkedNode* nextNode;
        DoublyLinkedNode* previousNode;
};
#endif // DOUBLYLINKEDNODE_H