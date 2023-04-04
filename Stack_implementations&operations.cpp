#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    bool push(int x) {
        Node* newNode = new Node;
        if (newNode == nullptr) {
            cout << "Error: memory allocation failed\n";
            return false;
        }
        newNode->data = x;
        newNode->next = top;
        top = newNode;
        cout << x << " pushed to stack\n";
        return true;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Error: stack underflow\n";
            return 0;
        }
        int x = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return x;
    }

    bool isEmpty() {
        return (top == nullptr);
    }

    int StackTop() {
        if (isEmpty()) {
            cout << "Error: stack is empty\n";
            return 0;
        }
        return top->data;
    }

    void Display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Elements in stack: ";
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    auto start_time = high_resolution_clock::now();
    Stack stack;
    stack.push(8);
    stack.push(10);
    stack.push(5);
    stack.push(11);
    stack.push(15);
    stack.push(23);
    stack.push(6);
    stack.push(18);
    stack.push(20);
    stack.push(17);
    stack.Display();
    cout << stack.pop() << " popped from stack\n";
    cout << stack.pop() << " popped from stack\n";
    cout << stack.pop() << " popped from stack\n";
    cout << stack.pop() << " popped from stack\n";
    cout << stack.pop() << " popped from stack\n";
    stack.Display();
    stack.push(4);
    stack.push(30);
    stack.push(3);
    stack.push(1);
    stack.Display();
    auto end_time = high_resolution_clock::now();
    auto execution_time = duration_cast<microseconds>(end_time - start_time);
    cout << "Execution time: " << execution_time.count() << " us" << endl;
    return 0;
}
