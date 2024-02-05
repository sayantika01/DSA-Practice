#include <iostream>

// Node structure to represent each element in the linked list
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to enqueue (push) a new element into the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        std::cout << value << " enqueued into the queue." << std::endl;
    }

    // Function to dequeue (pop) an element from the queue
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue Underflow. Cannot dequeue from an empty queue." << std::endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        std::cout << temp->data << " dequeued from the queue." << std::endl;
        delete temp;
    }

    // Function to get the front element of the queue without removing it
    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return -1; // Assuming -1 represents an invalid value for this example
        }
        return front->data;
    }

    // Function to display the elements of the queue
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        Node* current = front;
        std::cout << "Queue elements: ";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

// Main function for testing the queue
int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.display();

    std::cout << "Front element: " << queue.peek() << std::endl;

    queue.dequeue();
    queue.display();

    return 0;
}
