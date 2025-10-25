#include <iostream>
using namespace std;

struct Node{
    int val; 
    Node* next; 
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
