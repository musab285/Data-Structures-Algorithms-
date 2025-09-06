// Solve the following problem using a Singly Linked List.
// Given a Linked List of integers, write a function to modify the linked list such that all even numbers appear
// before all the odd numbers in the modified linked list. Also, keep the order of even and odd numbers same.

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
    void evenodd()
    {
        LinkedList *odd = new LinkedList();
        Node *oddtmp = nullptr;
        LinkedList *even = new LinkedList();
        Node *eventmp = nullptr;
        Node *tmp = head;
        while (tmp != nullptr)
        {
            if (tmp->val % 2 == 0)
            {
                if (even->head == nullptr)
                {
                    even->head = tmp;
                    eventmp = tmp;
                }
                else
                {
                    eventmp->next = tmp;
                    eventmp = eventmp->next;
                }
            }
            else
            {
                if (odd->head == nullptr)
                {
                    odd->head = tmp;
                    oddtmp = tmp;
                }
                else
                {
                    oddtmp->next = tmp;
                    oddtmp = oddtmp->next;
                }
            }
            tmp = tmp->next;
        }

        if (eventmp != nullptr)
            eventmp->next = nullptr;
        if (oddtmp != nullptr)
            oddtmp->next = nullptr;

        if (even->head != nullptr)
        {
            head = even->head;
            if (eventmp != nullptr)
                eventmp->next = odd->head;
            if (oddtmp != nullptr)
                tail = oddtmp;
            else
                tail = eventmp;
        }
        else
        {
            head = odd->head;
            tail = oddtmp;
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
    lst.insertAtEnd(17);
    lst.insertAtEnd(15);
    lst.insertAtEnd(8);
    lst.insertAtEnd(12);
    lst.insertAtEnd(10);
    lst.insertAtEnd(5);
    lst.insertAtEnd(4);
    lst.insertAtEnd(1);
    lst.insertAtEnd(7);
    lst.insertAtEnd(6);
    lst.display();
    lst.evenodd();
    cout << "After Update: " << endl;
    lst.display();
}