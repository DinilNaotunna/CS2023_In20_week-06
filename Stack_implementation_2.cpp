#include <iostream>
using namespace std;

class Node {
    public:
        int val;
        Node* next;
        
        Node(int value) {
            val = value;
            next = nullptr;
        }
};

class Stack {
    private:
        Node* top_node;
    public:
        Stack() {
            top_node = nullptr;
        }

        void push(int value) {
            Node* new_node = new Node(value);
            new_node->next = top_node;
            top_node = new_node;
        }

        int pop() {
            if (is_empty()) {
                cout << "Stack is empty" << endl;
                return -1;
            } else {
                int item = top_node->val;
                Node* temp = top_node;
                top_node = top_node->next;
                delete temp;
                return item;
            }
        }

        bool is_empty() {
            return top_node == nullptr;
        }

        int peek() {
            if (is_empty()) {
                cout << "Stack is empty" << endl;
                return -1;
            } else {
                return top_node->val;
            }
        }

        int size() {
            int count = 0;
            Node* curr = top_node;
            while (curr != nullptr) {
                count++;
                curr = curr->next;
            }
            return count;
        }
};
