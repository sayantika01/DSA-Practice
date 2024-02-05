#include <iostream>
using namespace std;

typedef struct LinkedList {
    int data;
    struct LinkedList *next;
} node;

node *create_node(int data) {
    node *temp = new node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insert_node(node *head, int data) {
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    node *a = create_node(data);
    temp->next = a;
}

void delete_node(node *head, int data) {
    node *temp = head;
    while (temp->next != NULL) {
        if (temp->next->data == data) {
            temp->next = temp->next->next;
            break;
        }
        temp = temp->next;
    }
}

void display(node *head) {
    node *temp = head->next; // Skip the head node
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverse(node *&head) {
    node *prev = NULL;
    node *current = head->next; // Skip the head node
    node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head->next = prev;
}

void insert_node_at_position(node *head, int data, int position) {
    node *temp = head;
    node *new_node = create_node(data);
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void insert_node_at_beginning(node *&head, int data) {
    node *temp = create_node(data);
    temp->next = head->next;
    head->next = temp;
}

void delete_node_at_position(node *head, int position) {
    node *temp = head;
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
    }
    temp->next = temp->next->next;
}

void delete_node_at_beginning(node *head) {
    head->next = head->next->next;
}

int main() {
    node *head = create_node(0);
    head->next = NULL;

    int choice;
    int data, position;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Display\n";
        cout << "4. Reverse\n";
        cout << "5. Insert Node at Position\n";
        cout << "6. Insert Node at Beginning\n";
        cout << "7. Delete Node at Position\n";
        cout << "8. Delete Node at Beginning\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter data to insert: ";
            cin >> data;
            insert_node(head, data);
            break;

        case 2:
            cout << "Enter data to delete: ";
            cin >> data;
            delete_node(head, data);
            break;

        case 3:
            cout << "Linked List: ";
            display(head);
            break;

        case 4:
            reverse(head);
            cout << "Reversed Linked List: ";
            display(head);
            break;

        case 5:
            cout << "Enter data to insert: ";
            cin >> data;
            cout << "Enter position to insert: ";
            cin >> position;
            insert_node_at_position(head, data, position);
            break;

        case 6:
            cout << "Enter data to insert at the beginning: ";
            cin >> data;
            insert_node_at_beginning(head, data);
            break;

        case 7:
            cout << "Enter position to delete: ";
            cin >> position;
            delete_node_at_position(head, position);
            break;

        case 8:
            delete_node_at_beginning(head);
            break;

        case 0:
            cout << "Exiting the program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}