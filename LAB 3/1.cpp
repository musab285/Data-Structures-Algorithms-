// You are given the array (3 1 2, 5, 8) of size 5 print that array on screen. Then create singly linked list from
// that array , Now add the 9 at the end , 11 pos 3, and 4 at the front and list. Now delete the 1, 2, and 5 then
// print the linked list.

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
        void insertInMiddle(int data, int pos){
            Node * nw = new Node(data); 
            if (pos == 1) {  
                nw->next = head;
                head = nw;
                if (tail == nullptr) tail = nw; 
                return;
            }

            Node * temp = head;
            int i = 1;  

            while(i < pos - 1 && temp != nullptr && temp->next != nullptr){
                temp = temp->next;
                i++;  
            }

            nw->next = temp->next;
            temp->next = nw;

            if (temp == tail) {
                tail = nw;
            }
        }

        void insertAtStart(int data){
            Node * nw = new Node(data); 
            nw->next = head; 
            head = nw; 
        }

        void deleteNode(int data) {
        if (head == nullptr) return;


        while (head != nullptr && head->val == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        Node* temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->next->val == data) {
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                if (toDelete == tail) {
                    tail = temp;
                }
                delete toDelete;
            }
            else {
                temp = temp->next;
            }
        }
    }

        void display(){
            Node * temp = head;
            int i = 1;  
            while(temp != tail){
                cout<<"Value at pos "<<i++<<": "<<temp->val<<endl;
                temp = temp->next; 
            }
            cout<<"Value at pos "<<i++<<": "<<temp->val<<endl;
        }
}; 

int main(){
    int arr[5] = {3,1, 2, 5, 8}; 
    for(int i=0; i<5; i++) cout<<arr[i]<<endl; 
    LinkedList lst; 
    cout << "Creating linked list from array:" << endl;
    lst.insertAtEnd(3);
    lst.insertAtEnd(1);
    lst.insertAtEnd(2);
    lst.insertAtEnd(5);
    lst.insertAtEnd(8);
    cout << "Initial linked list:" << endl;
    lst.display();

    cout << "Inserting 9 at the end:" << endl;
    lst.insertAtEnd(9);
    lst.display();

    cout << "Inserting 11 at position 3:" << endl;
    lst.insertInMiddle(11, 3);
    lst.display();

    cout << "Inserting 4 at the front:" << endl;
    lst.insertAtStart(4);
    lst.display();

    cout << "Deleting 1:" << endl;
    lst.deleteNode(1);
    lst.display();

    cout << "Deleting 2:" << endl;
    lst.deleteNode(2);
    lst.display();

    cout << "Deleting 5:" << endl;
    lst.deleteNode(5);
    lst.display();
}