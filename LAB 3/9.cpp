// Given a linked list, you have to perform the following task:
// 1. Extract the alternative nodes starting from second node.
// 2. Reverse the extracted list.
// 3. Append the extracted list at the end of the original list.
// Note: Try to solve the problem without using any extra memory.

#include <iostream>
using namespace std;

struct Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int data)
    {
        val = data;
        next = nullptr;
        prev = nullptr;
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
        nw->prev = tail;
        tail = nw;
    }

    void rearrange()
    {
        if (!head || !head->next)
            return;

        Node *curr = head;
        Node *altHead = nullptr;
        Node *altTail = nullptr;

        while (curr && curr->next)
        {
            Node *extracted = curr->next;
            curr->next = extracted->next;
            if (extracted->next)
                extracted->next->prev = curr;

            extracted->next = nullptr;
            extracted->prev = nullptr;

            if (!altHead)
                altHead = altTail = extracted;
            else
            {
                altTail->next = extracted;
                extracted->prev = altTail;
                altTail = extracted;
            }

            curr = curr->next;
        }

        Node *prev = nullptr;
        Node *currAlt = altHead;
        while (currAlt)
        {
            Node *nxt = currAlt->next;
            currAlt->next = prev;
            currAlt->prev = nxt;
            prev = currAlt;
            currAlt = nxt;
        }
        altHead = prev;

        if (altHead)
        {
            tail->next = altHead;
            altHead->prev = tail;

            Node *temp = altHead;
            while (temp->next)
                temp = temp->next;
            tail = temp;
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
    LinkedList L;
    L.insertAtEnd(1);
    L.insertAtEnd(2);
    L.insertAtEnd(3);
    L.insertAtEnd(4);
    L.insertAtEnd(5);
    cout << "Original list:" << endl;
    L.display();
    L.rearrange();
    cout << "After rearrange:" << endl;
    L.display();
}
