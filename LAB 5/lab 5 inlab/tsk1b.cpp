#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;
};

Node* reverseDoublyRecursive(Node* head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) {
        head->prev = nullptr;
        return head;
    }

    Node* newHead = reverseDoublyRecursive(head->next);

    head->next->next = head;
    head->prev = head->next;
    head->next = nullptr;

    return newHead;
}

int main() {
    Node* head = new Node{1, nullptr, nullptr};
    Node* second = new Node{2, nullptr, head};
    head->next = second;
    Node* third = new Node{3, nullptr, second};
    second->next = third;

    Node* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    head = reverseDoublyRecursive(head);

    cout<<endl<<"reversed"<<endl ; 

    Node* temp1 = head;
    while (temp1) {
        cout << temp1->val << " ";
        temp1 = temp1->next;
    }

    return 0;
}
