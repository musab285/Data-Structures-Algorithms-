// Task 5:
// Implement Quick Sort using linked list in C++. Define a node for a linked list with integer data
// and a pointer to the next node. Write a function to swap two nodes in the linked list. Write a
// function to partition the linked list using the last node as the pivot. Implement the Quick Sort
// algorithm using the partition function and the swap function. Finally, write a function to print the
// sorted linked list. Your implementation should be able to handle empty linked lists and linked lists
// with only one node. Test your implementation with a sample linked list containing the following
// integers: 10, 7, 8, 9, 1, 5, 3. The expected output after sorting should be: 1 3 5 7 8 9 10.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void swap(Node* a, Node* b) {
    if (!a || !b) return;
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

Node* partition(Node* low, Node* high) {
    int pivot = high->data;
    Node* i = low;
    Node* j = low;

    while (j != high) {
        if (j->data < pivot) {
            swap(i, j);
            i = i->next;
        }
        j = j->next;
    }
    swap(i, high);
    return i;
}

Node* getPrev(Node* start, Node* node) {
    Node* prev = nullptr;
    while (start && start != node) {
        prev = start;
        start = start->next;
    }
    return prev;
}

void quickSort(Node* low, Node* high) {
    if (!low || !high || low == high) return;

    Node* p = partition(low, high);

    Node* prev = getPrev(low, p);
    if (prev != nullptr)
        quickSort(low, prev);
    if (p->next != nullptr)
        quickSort(p->next, high);
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node{10, nullptr};
    head->next = new Node{7, nullptr};
    head->next->next = new Node{8, nullptr};
    head->next->next->next = new Node{9, nullptr};
    head->next->next->next->next = new Node{1, nullptr};
    head->next->next->next->next->next = new Node{5, nullptr};
    head->next->next->next->next->next->next = new Node{3, nullptr};

    if (!head || !head->next) {
        cout << "Sorted linked list: ";
        printList(head);
        return 0;
    }

    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    quickSort(head, tail);

    cout << "Sorted linked list: ";
    printList(head);

    return 0;
}
