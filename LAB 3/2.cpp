// Write a program that prompts the user to enter a number indicating how many elements to move to the
// end of a linked list. The program should then move that exact number of elements from the beginning of
// the linked list to the end.
// Example: given list: 5, 3 1 8 6 4 2
// Enter the number: 2
// After rotation: 1 8 6 4 2 5 3

#include <iostream>
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

class LinkedList
{
public:
    Node *head;
    Node *tail;
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(int data)
    {
        Node *nw = new Node(data);
        if (head == nullptr)
        {
            head = tail = nw;
        }
        tail->next = nw;
        tail = nw;
    }
    void movetoend(int n)
    {
        for (int i = 0; i < n; i++)
        {
            Node *tmp = head;
            head = head->next;
            tail->next = tmp;

            tail = tmp;

            tail->next = nullptr;
        }
    }
    void display()
    {
        Node *temp = head;
        int i = 1;
        while (temp != tail)
        {
            cout << "Value at pos " << i++ << ": " << temp->val << endl;
            temp = temp->next;
        }
        cout << "Value at pos " << i++ << ": " << temp->val << endl;
    }
};

int main()
{
    LinkedList lst;
    lst.insertAtEnd(5);
    lst.insertAtEnd(3);
    lst.insertAtEnd(1);
    lst.insertAtEnd(8);
    lst.insertAtEnd(6);
    lst.insertAtEnd(4);
    lst.insertAtEnd(2);
    lst.display();
    lst.movetoend(2);
    cout << "After update: " << endl;
    lst.display();
}