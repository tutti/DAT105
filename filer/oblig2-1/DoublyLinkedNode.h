#ifndef DOUBLYLINKEDNODE_H
#define DOUBLYLINKEDNODE_H

using namespace std;

template<class T>
class DoublyLinkedNode {
    public:
        DoublyLinkedNode() {
            this->data = nullptr;
            this->previous = nullptr;
            this->next = nullptr;
        };

        DoublyLinkedNode(T* data) {
            this->data = data;
            this->previous = nullptr;
            this->next = nullptr;
        }

        DoublyLinkedNode(T* data, DoublyLinkedNode<T>* previous, DoublyLinkedNode<T>* next) {
            this->data = data;
            this->previous = previous;
            this->next = next;
        }

        // There's no destructor here.
        // This node has no business deleting its next or previous nodes,
        // and does not own its data.

        T* getData() const {
            return this->data;
        }

        DoublyLinkedNode<T>* getPrevious() const {
            return this->previous;
        }

        DoublyLinkedNode<T>* getNext() const {
            return this->next;
        }

        void setData(T* data) {
            this->data = data;
        }

        void setPrevious(DoublyLinkedNode<T>* previous) {
            this->previous = previous;
        }

        void setNext(DoublyLinkedNode<T>* next) {
            this->next = next;
        }
    protected:
        T* data;
        DoublyLinkedNode<T>* previous;
        DoublyLinkedNode<T>* next;
};

#endif