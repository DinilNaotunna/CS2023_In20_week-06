#include <iostream>
using namespace std;

class Stack {
    private:
        int* elements;
        int topIndex;
        int capacity;
    public:
        Stack(int size) {
            elements = new int[size];
            capacity = size;
            topIndex = -1;
        }

        ~Stack() {
            delete[] elements;
        }

        void push(int x) {
            if (isFull()) {
                cout << "Stack is full" << endl;
            } else {
                topIndex++;
                elements[topIndex] = x;
            }
        }

        int pop() {
            if (isEmpty()) {
                cout << "Stack is empty" << endl;
                return -1;
            } else {
                int poppedElement = elements[topIndex];
                topIndex--;
                return poppedElement;
            }
        }

        bool isEmpty() {
            return topIndex == -1;
        }

        bool isFull() {
            return topIndex == capacity - 1;
        }

        int peek() {
            if (isEmpty()) {
                cout << "Stack is empty" << endl;
                return -1;
            } else {
                return elements[topIndex];
            }
        }

        int size() {
            return topIndex + 1;
        }
};
