// Task 7: Consider a library where books are borrowed and returned by multiple patrons. The library
// has a limited number of staff members to handle the book transactions. As patrons arrive with books
// to borrow or return, they are added to a linear queue. Each book transaction can take a variable amount
// of time to complete, depending on factors such as the number of books being borrowed or returned,
// and the availability of the staff members. Once a book transaction is completed, the next patron in the
// queue is serviced.
// Write a C++ program that simulates this library scenario using a linear queue data structure. The
// program should allow patrons to add themselves to the queue, remove themselves from the queue
// when their book transaction is completed, and display the current queue of patrons waiting for book
// transactions to be serviced.

#include <iostream>
#include <string>
using namespace std;

struct Patron {
    string name;
    int duration;
};

class LinearQueue {
    Patron* data;
    int capacity;
    int front;
    int rear;
public:
    LinearQueue(int cap = 100) : capacity(cap), front(0), rear(-1) {
        data = new Patron[capacity];
    }
    ~LinearQueue() {
        delete[] data;
    }
    bool isEmpty() const {
        return rear < front;
    }
    bool isFull() const {
        return rear == capacity - 1;
    }
    void compact() {
        if (front == 0) return;
        int j = 0;
        for (int i = front; i <= rear; ++i) data[j++] = data[i];
        front = 0;
        rear = j - 1;
    }
    bool enqueue(const string& name, int duration) {
        if (isFull()) {
            if (front > 0) {
                compact();
            } else {
                cout << "Queue is full\n";
                return false;
            }
        }
        data[++rear] = {name, duration};
        return true;
    }
    bool dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return false;
        }
        Patron p = data[front++];
        cout << "Processing patron: " << p.name << " (duration " << p.duration << "s)\n";
        cout << "Simulating processing for " << (p.duration > 0 ? p.duration : 0) << " seconds...\n";
        cout << "Completed: " << p.name << '\n';
        if (isEmpty()) {
            front = 0;
            rear = -1;
        }
        return true;
    }
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Current queue:\n";
        for (int i = front; i <= rear; ++i) {
            cout << i - front + 1 << ". " << data[i].name << " (" << data[i].duration << "s)\n";
        }
    }
};

int main() {
    int cap;
    cout << "Enter queue capacity: ";
    if (!(cin >> cap) || cap <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cap = 100;
    }
    LinearQueue q(cap);
    while (true) {
        cout << "\n1. Add patron\n2. Process next patron\n3. Display queue\n4. Exit\nChoose: ";
        int choice;
        if (!(cin >> choice)) break;
        if (choice == 1) {
            string name;
            int duration;
            cin.ignore(1000, '\n');
            cout << "Enter patron name: ";
            getline(cin, name);
            cout << "Enter transaction duration (seconds): ";
            if (!(cin >> duration)) {
                cin.clear();
                cin.ignore(1000, '\n');
                duration = 1;
            }
            q.enqueue(name, duration);
        } else if (choice == 2) {
            q.dequeue();
        } else if (choice == 3) {
            q.display();
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice\n";
        }
    }
    return 0;
}