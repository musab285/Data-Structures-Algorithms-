// Create a circular link list and perform the mentioned tasks.
// a. Insert a new node at the end of the list.
// b. Insert a new node at the beginning of list.
// c. Insert a new node at given position.
// d. Delete any node.
// e. Print the complete circular link list.

#include<iostream>
using namespace std;

struct Node
{
public:
    int val;
    Node *next;
    Node(int data)
    {
        val = data;
        next = nullptr;
    }
};

class CircularLinkedList
{
public:
    Node *head;
    Node *tail;
    CircularLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(int data)
    {
        Node *nw = new Node(data);
        if (!head)
        {
            head = tail = nw;
            nw->next = head;
        }
        else
        {
            tail->next = nw;
            nw->next = head;
            tail = nw;
        }
    }

    void insertAtBeginning(int data)
    {
        Node *nw = new Node(data);
        if (!head)
        {
            head = tail = nw;
            nw->next = head;
        }
        else
        {
            nw->next = head;
            head = nw;
            tail->next = head;
        }
    }

    void insertAtPosition(int data, int pos)
    {
        if (pos == 1)
        {
            insertAtBeginning(data);
            return;
        }
        Node *nw = new Node(data);
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp->next != head; i++)
            temp = temp->next;
        nw->next = temp->next;
        temp->next = nw;
        if (temp == tail) tail = nw;
    }

    void deleteNode(int key)
    {
        if (!head) return;
        Node *curr = head, *prev = tail;
        do
        {
            if (curr->val == key)
            {
                if (curr == head)
                {
                    head = head->next;
                    tail->next = head;
                }
                else if (curr == tail)
                {
                    tail = prev;
                    tail->next = head;
                }
                else
                {
                    prev->next = curr->next;
                }
                delete curr;
                if (head == tail && head->val == key)
                {
                    delete head;
                    head = tail = nullptr;
                }
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
    }

    void display()
    {
        if (!head) return;
        Node *temp = head;
        int i = 1;
        do
        {
            cout << "Value at pos " << i++ << ": " << temp->val << endl;
            temp = temp->next;
        } while (temp != head);
    }
};

int main()
{
    CircularLinkedList cl;
    cl.insertAtEnd(1);
    cl.insertAtEnd(2);
    cl.insertAtEnd(3);
    cl.insertAtBeginning(0);
    cl.insertAtPosition(9, 3);
    cl.display();
    cout << "After deleting 2:" << endl;
    cl.deleteNode(2);
    cl.display();
}

