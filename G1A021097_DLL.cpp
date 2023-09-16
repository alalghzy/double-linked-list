#include <iostream>
using namespace std;

struct Node {
    long data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;
Node* tail = nullptr;

void initialize() {
    head = nullptr;
    tail = nullptr;
}

bool isEmpty() {
    return head == nullptr;
}

void insert(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void remove() {
    if (isEmpty()) {
        cout << "Linked list is empty." << endl;
        return;
    }

    long removedData = head->data;
    Node* temp = head;

    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }

    delete temp;
    cout << removedData << " has been removed." << endl;
}

void print() {
    if (isEmpty()) {
        cout << "Linked list is empty." << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        cout << current->data << "\t";
        current = current->next;
    }
    cout << endl;
}

int main() {
    initialize();
    char choice, repeat;
    long data;

    do {
        system("CLS");
        cout << "DOUBLE LINKED LIST PROGRAM" << endl;
        cout << "---------------------------" << endl;
        cout << "Menu:\n";
        cout << "1. Add Data\n";
        cout << "2. Remove Data\n";
        cout << "3. Display Data\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Enter data: ";
                cin >> data;
                insert(data);
                cout << data << " added." << endl;
                break;
            case '2':
                remove();
                break;
            case '3':
                print();
                break;
            case '4':
                cout << "Thank you!" << endl;
                exit(0);
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << "Return to menu? (y/n): ";
        cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
