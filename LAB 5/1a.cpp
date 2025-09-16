// Insert the element at the end of linked list and display the list in reverse direction using Recursion
// Approach?

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
        // void display(){
        //     Node * temp = head;
        //     int i = 1;  
        //     while(temp != tail){
        //         cout<<"Value at pos "<<i++<<": "<<temp->val<<endl;
        //         temp = temp->next; 
        //     }
        //     cout<<"Value at pos "<<i++<<": "<<temp->val<<endl;
        // }
}; 

void reverse(Node * head){
    if(head == NULL){
        return; 
    }
    reverse(head->next);
    cout<<head->val<<" "; 
}

int main(){
    LinkedList lst; 
    lst.insertAtEnd(3);
    lst.insertAtEnd(1);
    lst.insertAtEnd(2);
    lst.insertAtEnd(5);
    lst.insertAtEnd(8);
    cout << "Initial linked list:" << endl;
    // lst.display();
    reverse(lst.head); 

}