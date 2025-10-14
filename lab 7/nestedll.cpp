#include <iostream>
using namespace std;

struct Node2 {
    int data2;
    Node2* next2;
    Node2(int data) {
        this->data2 = data;   
        next2 = nullptr;
    }
};

struct Node {
    int data;
    Node* next;
    Node2* head2;
    Node(int data) {
        this->data = data;
        next = nullptr;
        head2 = nullptr;
    }
};

class NLL {
    Node* head;

public:
    NLL() {
        head = nullptr;
    }

    // Insert a node into the main linked list
    void insert_main_node(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Search for a main node by value
    Node* search_node(int val) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == val)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    void insert_sub_node(int mainValue, int subValue) {
        Node* mainNode = search_node(mainValue);
        if (mainNode == nullptr) {
            cout << "Main node not found!\n";
            return;
        }

        Node2* newSub = new Node2(subValue);
        if (mainNode->head2 == nullptr) {
            mainNode->head2 = newSub;
        } else {
            Node2* temp2 = mainNode->head2;
            while (temp2->next2 != nullptr) {
                temp2 = temp2->next2;
            }
            temp2->next2 = newSub;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Main Node " << temp->data << ": ";
            Node2* sub = temp->head2;
            while (sub != nullptr) {
                cout << sub->data2 << " -> ";
                sub = sub->next2;
            }
            cout << "NULL" << endl;
            temp = temp->next;
        }
    }
};

int main() {
    NLL list;
    list.insert_main_node(10);
    list.insert_main_node(20);
    list.insert_main_node(30);

    list.insert_sub_node(10, 1);
    list.insert_sub_node(10, 2);
    list.insert_sub_node(20, 5);
    list.insert_sub_node(30, 7);
    list.insert_sub_node(30, 8);

    list.display();

    return 0;
}