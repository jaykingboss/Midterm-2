#include <iostream>
#include <string>
using namespace std;

const int NUM_CUSTOMERS = 5;    // Initial number of customers
const int TIME_PERIODS = 20;     // Total time periods for the simulation
const int MAX_NAMES = 30;        // Maximum number of names

class DoublyLinkedList {
private:
    struct Node {
        string data;
        Node* prev;
        Node* next;
        Node(string val, Node* p = nullptr, Node* n = nullptr) {
            data = val;
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void push_back(string value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(string value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void pop_front() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
        if (!head) tail = nullptr; 
    }

    void pop_back() {
        if (!tail) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        delete temp;
        if (!tail) head = nullptr; 
    }

    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << "        " << current->data << endl; 
            current = current->next;
        }
    }

    bool is_empty() {
        return head == nullptr;
    }

    Node* get_head() {
        return head;
    }

    Node* get_tail() {
        return tail;
    }
};

// Function to generate a random number between min and max
int random(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Main simulation function
void simulateCoffeeShop(string names[], int nameCount) {
    DoublyLinkedList queue;
    srand(1);  // random number 

   
    }
}

