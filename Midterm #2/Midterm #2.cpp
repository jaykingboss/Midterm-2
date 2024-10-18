#include <iostream>
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
};

void simulateCoffeeShop(string names[], int nameCount) {
    DoublyLinkedList queue;
    srand(1); 
}

int main() {
    string names[MAX_NAMES] = {
        "Jean", "Iris", "Omar", "Andy", "Drew",
    };
    int nameCount = 20;  // Number of names in the array
    simulateCoffeeShop(names, nameCount);  // Run test
    return 0;
}
