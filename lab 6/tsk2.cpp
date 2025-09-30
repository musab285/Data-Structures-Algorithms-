#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void bubbleSort(Node* head) {
    if (!head) return;
    bool swapped;
    do {
        swapped = false;
        Node* curr = head;
        while (curr->next) {
            if (curr->data > curr->next->data) {
                swap(curr->data, curr->next->data);
                swapped = true;
            }
            curr = curr->next;
        }
    } while (swapped);
}

void insertAlternate(Node* &head1, Node* &head2) {
    Node* curr1 = head1;
    Node* curr2 = head2;
    while (curr1 && curr2) {
        Node* temp1 = curr1->next;
        Node* temp2 = curr2->next;
        curr1->next = curr2;
        curr2->next = temp1;
        curr1 = temp1;
        curr2 = temp2;
    }
    head2 = curr2;
}

void display(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head1 = new Node{1, new Node{2, new Node{3, NULL}}};
    Node* head2 = new Node{4, new Node{5, new Node{6, new Node{7, new Node{8, NULL}}}}};
    bubbleSort(head1);
    insertAlternate(head1, head2);
    display(head1);
    display(head2);
}