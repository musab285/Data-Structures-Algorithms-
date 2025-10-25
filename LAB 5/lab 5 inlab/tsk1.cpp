#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

class LL {
public:
    Node* head;
    Node* tail;

    LL() {
        head = nullptr;
        tail = nullptr;
    }

    void add(int val) {
        addRecursive(head, val);
    }

    void addRecursive(Node*& current, int val) {
        if (current == nullptr) {
            current = new Node();
            current->val = val;
            current->next = nullptr;
            if (tail == nullptr)
                tail = current;
            return;
        }
        addRecursive(current->next, val);
    }

    void dltstrt() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) tail = nullptr;
    }

    void dltend() {
        deleteEndRecursive(head);
    }

    void deleteEndRecursive(Node*& current) {
        if (current == nullptr) return;
        if (current->next == nullptr) {
            delete current;
            current = nullptr;
            tail = nullptr;
            return;
        }
        if (current->next->next == nullptr) {
            delete current->next;
            current->next = nullptr;
            tail = current;
            return;
        }
        deleteEndRecursive(current->next);
    }

    void dltmddl(int pos) {
        if (pos == 0) {
            dltstrt();
            return;
        }
        deleteMiddleRecursive(head, pos, 0);
    }

    void deleteMiddleRecursive(Node*& current, int pos, int idx) {
        if (current == nullptr || current->next == nullptr) return;
        if (idx == pos - 1) {
            Node* temp = current->next;
            current->next = temp->next;
            if (current->next == nullptr) tail = current;
            delete temp;
            return;
        }
        deleteMiddleRecursive(current->next, pos, idx + 1);
    }

    void display() {
        displayRecursive(head);
    }

    void displayRecursive(Node* current) {
        if (current == nullptr) return;
        cout << current->val << endl;
        displayRecursive(current->next);
    }
};

int main() {
    LL* one = new LL();
    one->add(2);
    one->add(26);
    one->add(25);
    one->add(7);
    one->add(2);
    one->display();

    one->dltend();
    one->dltstrt();
    one->dltmddl(2);
    cout << "delted" << endl;

    one->display();

    delete one;
}
