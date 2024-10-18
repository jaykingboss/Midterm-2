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

int random(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void CoffeeShop(string names[], int nameCount) {
    DoublyLinkedList queue;
    srand(1);  // random number 

    // Initial customer addition at the start
    cout << "Store opens:\n";
    for (int i = 0; i < NUM_CUSTOMERS; ++i) {
        string name = names[random(0, nameCount - 1)];
        queue.push_back(name);
        cout << "    " << name << " joins the line\n";
    }

    cout << "Resulting line:\n";
    queue.print(); 

    
    for (int t = 1; t <= TIME_PERIODS; ++t) {
        cout << "Time step #" << t << ":\n";

        // Check for 40% chance of serving the first customer
        if (!queue.is_empty() && random(1, 100) <= 40) {
            
        }

        // Check for 60% chance of new customer joining
        if (random(1, 100) <= 60) {
            
        }

        // Check for 20% chance of last customer leaving
        if (!queue.is_empty() && random(1, 100) <= 20) {
          
        }

        // Check for 10% chance of any particular customer leaving
        if (!queue.is_empty() && random(1, 100) <= 10) {
            
        }

        // Check for 10% chance of VIP customer
        if (random(1, 100) <= 10) {
           
        }

        
    }
}

int main() {
    string names[MAX_NAMES] = {
        "Jean", "Iris", "Omar", "Andy", "Drew",
        "Leah", "Hope", "Mia", "Liam", "Noah",
        "Emma", "Sophia", "Olivia", "Ava", "Isabella",
        "Lucas", "Ethan", "Mason", "Logan", "James"
    };  
    int nameCount = 20;  
    CoffeeShop(names, nameCount);  
    return 0;
}
