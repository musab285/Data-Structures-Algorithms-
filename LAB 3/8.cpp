// Give an efficient algorithm for concatenating two doubly linked lists L and M, with head and tail preserved
// nodes, into a single list that contains all the nodes of L followed by all the nodes of M.

#include<iostream>
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

void merge(LinkedList &l, LinkedList &m){
    if(l.head == nullptr){
        l.head = m.head; 
        l.tail = m.tail; 
        return; 
    }
    if(m.head == nullptr) return; 

    l.tail->next = m.head; 
    m.head->prev = l.tail; 
    l.tail = m.tail;
}

int main()
{
    LinkedList l1; 
    l1.insertAtEnd(1); 
    l1.insertAtEnd(2); 
    l1.insertAtEnd(3); 
    cout<<"List 1: "<<endl; 
    l1.display(); 

    LinkedList l2; 
    l2.insertAtEnd(4); 
    l2.insertAtEnd(5); 
    l2.insertAtEnd(6); 
    cout<<"List 2: "<<endl; 
    l2.display(); 

    merge(l1, l2); 
    cout<<"After Merging: "<<endl; 
    l1.display(); 

}
