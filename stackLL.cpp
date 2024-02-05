#include <iostream>

// Node structure to represent each element in the linked list
struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

// Stack class
class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to push a new element onto the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        std::cout << value << " pushed onto the stack." << std::endl;
    }

    // Function to pop the top element from the stack
    void pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow. Cannot pop from an empty stack." << std::endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        std::cout << temp->data << " popped from the stack." << std::endl;
        delete temp;
    }

    // Function to get the top element of the stack without removing it
    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return -1; // Assuming -1 represents an invalid value for this example
        }
        return top->data;
    }

    // Function to display the elements of the stack
    void display() {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        Node* current = top;
        std::cout << "Stack elements: ";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};