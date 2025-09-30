#include <iostream>
using namespace std;

class Student {
public:
    int roll;
    string name;
    Student() {}
    Student(int rll, string nm) : roll(rll), name(nm) {}
};

class Node {
public:
    Student* std;
    Node* next;
    Node* prv;
    Node(int rll, string nm) {
        std = new Student(rll, nm);
        next = nullptr;
        prv = nullptr;
    }
    ~Node() {
        delete std;
    }
};

class LL {
    Node* head;
public:
    LL() {
        head = nullptr;
    }

    void addnode(int rll, string nm, int position) {
        Node* nw = new Node(rll, nm);

        if (head == nullptr) {
            head = nw;
            return;
        }

        Node* tmp = head;
        int cnt = 0;

        while (tmp != nullptr && cnt < position - 1) {
            tmp = tmp->next;
            cnt++;
        }

        if (tmp == nullptr) {
            cout << "Invalid position!" << endl;
            delete nw;
            return;
        }

        nw->next = tmp->next;
        nw->prv = tmp;
        if (tmp->next != nullptr) {
            tmp->next->prv = nw;
        }
        tmp->next = nw;
    }

    void display() {
        Node* tmp = head;
        while (tmp != nullptr) {
            cout << tmp->std->name << " " << tmp->std->roll << endl;
            tmp = tmp->next;
        }
    }
};

int main() {
    LL* one = new LL();
    one->addnode(24, "musab", 0);
    one->addnode(26, "sufi", 1);
    one->addnode(25, "zein", 2);
    one->addnode(7, "moelester", 3);
    one->addnode(2, "goofy", 2);

    one->display();

}
