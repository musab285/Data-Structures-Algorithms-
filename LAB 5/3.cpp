// Write a C++ function to find the length of a singly linked list using tail recursion?

#include<iostream>
using namespace std; 

#include <iostream>
using namespace std; 

struct Node{
    public:
        int val;
        Node * next; 
        Node(int data){
            val = data; 
            next = nullptr;  
        } 
};

class LinkedList{
    public:
        Node * head; 
        Node * tail; 
        LinkedList(){
            head = nullptr; 
            tail = nullptr; 
        }        
        void insertAtEnd(int data){
            Node * nw = new Node(data); 
            if(head == nullptr){
                head = tail = nw;  
            }
            tail->next = nw; 
            tail = nw; 
        }
        
}; 

int length(Node * head, int n){
    if(head == NULL){
        return n; 
    }
    return length(head->next, n+1); 
}

int main(){
    LinkedList lst; 
    lst.insertAtEnd(3);
    lst.insertAtEnd(1);
    lst.insertAtEnd(2);
    lst.insertAtEnd(5);
    lst.insertAtEnd(8);
    cout << "Initial linked list:" << endl; 
    cout<<length(lst.head, 0); 
}