#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <vector>
#include <string>
#include <iostream>
#include <functional>

using namespace std;

template<class T>
class PriorityQueue {
    public:
        PriorityQueue() {
            this->comparator = nullptr;
        }

        PriorityQueue(function<int(T a, T b)> comparator) {
            this->comparator = comparator;
        }

        ~PriorityQueue() {
            // The elements in the vector need to be deleted, as they're pointers,
            // but the vector itself is on the stack and does not need to be
            // deleted. The comparator may or may not be on the stack, but the
            // priority queue only got the actual object.
            for (int i = 0; i < elements.size(); ++i) {
                delete elements[i];
            }
        }

        virtual void add(T* t) {
            // Insert the element at the end of the heap
            this->elements.push_back(t);

            // Get the position of the last element (equal to vector size - 1).
            int position = this->elements.size() - 1;

            // Swap element upwards until it reaches its correct position
            while (position > 0 && this->compare(this->elements[position], this->elements[this->parent(position)]) > 0) {
                this->swap(this->parent(position), position);
                position = this->parent(position);
            }
        }

        virtual T* remove() {
            if (this->isEmpty()) {
                throw new runtime_error("Priority queue has no elements.");
            }

            // Take out the first element and swap the last element up
            T* elmt = this->elements.front();
            swap(0, this->elements.size() - 1);
            this->elements.pop_back();

            // Swap the new top element down until it's greater than both its children
            int position = 0;
            while (this->hasChild(position) && this->compare(this->elements[this->greaterChild(position)], this->elements[position]) > 0) {
                int newPosition = this->greaterChild(position);
                this->swap(position, newPosition);
                position = newPosition;
            }

            return elmt;
        }

        virtual bool isEmpty() {
            return elements.empty();
        }

        void operator+=(T* t) {
            this->add(t);
        }

        friend ostream& operator<<(ostream& ostr, const PriorityQueue& q) {
            for (int i = 0; i < q.elements.size(); ++i) {
                if (i > 0) {
                    ostr << ", ";
                }
                ostr << *q.elements[i];
            }

            return ostr;
        }

    protected:
        vector<T*> elements;
        function<int(T a, T b)> comparator;

    private:
        int compare(T* a, T* b) {
            if (comparator != nullptr) {
                return comparator(*a, *b);
            }
            if (*a > *b) {
                return 1;
            } else if (*a < *b) {
                return -1;
            } else {
                return 0;
            }
        }

        void swap(int a, int b) {
            T* temp = elements[a];
            elements[a] = elements[b];
            elements[b] = temp;
        }

        bool hasChild(int parent) {
            return (elements.size() >= 2*(parent+1));
        }

        int leftChild(int parent) {
            return 2*parent + 1;
        }

        int rightChild(int parent) {
            return 2*parent + 2;
        }

        int greaterChild(int parent) {
            if (!hasChild(parent)) {
                throw new logic_error("Parent has no children.");
            }
            // If the right child doesn't exist, return the left child.
            if (rightChild(parent) >= elements.size()) {
                return leftChild(parent);
            }
            // If the left child is greater or equal, return it.
            if (compare(elements[leftChild(parent)], elements[rightChild(parent)]) > 0) {
                return leftChild(parent);
            }
            return rightChild(parent);
        }

        int parent(int child) {
            return (child - 1) / 2;
        }
};

#endif