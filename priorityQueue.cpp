#include <iostream>
#include <cstdlib>

using namespace std;

// Node structure to represent each element in the linked list
struct Node {
    int data;
    int priority;
    Node* next;

    Node(int value, int p) : data(value), priority(p), next(nullptr) {}
};

// Priority Queue class
class PriorityQueue {
private:
    Node* front;

public:
    PriorityQueue() : front(nullptr) {}

    // Function to check if the priority queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to insert (enqueue) a new element into the priority queue
    void enqueue(int value, int priority) {
        Node* newNode = new Node(value, priority);
        if (isEmpty() || priority > front->priority) {
            newNode->next = front;
            front = newNode;
        } else {
            Node* temp = front;
            while (temp->next != nullptr && temp->next->priority > priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        cout << "Enqueued (" << value << ", Priority: " << priority << ") into the priority queue." << endl;
    }

    // Function to remove (dequeue) the element with the highest priority
    void dequeue() {
        if (isEmpty()) {
            cout << "Priority Queue Underflow. Cannot dequeue from an empty priority queue." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        cout << "Dequeued (" << temp->data << ", Priority: " << temp->priority << ") from the priority queue." << endl;
        delete temp;
    }

    // Function to display the elements of the priority queue
    void display() {
        if (isEmpty()) {
            cout << "Priority Queue is empty." << endl;
            return;
        }
        Node* current = front;
        cout << "Priority Queue elements: ";
        while (current != nullptr) {
            cout << "(" << current->data << ", Priority: " << current->priority << ") ";
            current = current->next;
        }
        cout << endl;
    }
};

// Main function for testing the priority queue
int main() {
    PriorityQueue priorityQueue;

    priorityQueue.enqueue(10, 2);
    priorityQueue.enqueue(20, 1);
    priorityQueue.enqueue(30, 3);

    priorityQueue.display();

    priorityQueue.dequeue();
    priorityQueue.display();

    return 0;
}
