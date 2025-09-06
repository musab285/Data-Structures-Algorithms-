// Delete a value from any position (not the first one only) from the singly linked list if it’s present in the
// list otherwise show a message to the user that the value is not present in the list.

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

    void deleteNode(int data)
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        bool found = false;

        while (head != nullptr && head->val == data)
        {
            found = true;
            Node *temp = head;
            head = head->next;
            delete temp;
        }

        Node *temp = head;
        while (temp != nullptr && temp->next != nullptr)
        {
            if (temp->next->val == data)
            {
                found = true;
                Node *toDelete = temp->next;
                temp->next = temp->next->next;
                if (toDelete == tail)
                {
                    tail = temp;
                }
                delete toDelete;
            }
            else
            {
                temp = temp->next;
            }
        }

        if (!found)
        {
            cout << "Value " << data << " is not present in the list." << endl;
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
    lst.insertAtEnd(1);
    lst.insertAtEnd(2);
    lst.insertAtEnd(3);
    lst.insertAtEnd(4);
    lst.insertAtEnd(5);
    lst.display();
    lst.deleteNode(3);
    cout << "After deletion:" << endl;
    lst.display();
    lst.deleteNode(10); 
}