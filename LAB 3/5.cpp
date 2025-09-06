// Solve the following problem using a Singly Linked List.
// Given a Linked List of integers or string, write a function to check if the entirety of the linked list is a
// palindrome or not

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

    bool isPalindrome(){
        Node *tmp1 = head; 
        Node *tmp2 = tail; 
        while(tmp1!=tmp2){
            if(tmp1->val != tmp2->val) return false; 
            tmp1 = tmp1->next; tmp2=tmp2->prev; 
        }
        return true; 
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

int main(){
    LinkedList lst; 
    lst.insertAtEnd(1); 
    lst.insertAtEnd(0); 
    lst.insertAtEnd(2); 
    lst.insertAtEnd(0); 
    lst.insertAtEnd(1); 
    if(lst.isPalindrome()) cout<<"List is a palindrome"<<endl ; 
    else cout<<"List is not a palindrome"<<endl; 
    
    LinkedList lst1; 
    lst1.insertAtEnd(1); 
    lst1.insertAtEnd(0); 
    lst1.insertAtEnd(1); 
    lst1.insertAtEnd(1); 
    lst1.insertAtEnd(1); 
    lst1.insertAtEnd(4); 
    lst1.insertAtEnd(5); 
    if(lst1.isPalindrome()) cout<<"Second List is a palindrome"<<endl ; 
    else cout<<"Second List is not a palindrome"<<endl; 
} 