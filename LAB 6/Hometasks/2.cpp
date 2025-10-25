// Task 2: Suppose you are implementing a program to keep track of a user's web browsing history using
// a linked list and a stack. Whenever the user visits a new website, the website URL is added to the front
// of the linked list to represent the most recent page visited. Additionally, the website URL is pushed
// onto a stack to allow for the user to easily navigate back to the previous page.
// Now suppose the user has visited 5 websites in the following order: Google, Facebook, Twitter,
// LinkedIn, and Instagram. The user decides to click the "back" button twice to return to the Facebook
// page. Write a function to implement this behavior using the linked list and stack.
// Hint: You will need to pop two elements from the stack and remove the first two nodes from the
// linked list.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
    string url;
    Node* next;
    Node(const string& u): url(u), next(nullptr) {}
};

void addFront(Node*& head, const string& url) {
    Node* n = new Node(url);
    n->next = head;
    head = n;
}

void removeFront(Node*& head) {
    if (!head) return;
    Node* tmp = head;
    head = head->next;
    delete tmp;
}

struct Stack {
    vector<string> data;
    void push(const string& s) { data.push_back(s); }
    void pop() { if (!data.empty()) data.pop_back(); }
    bool empty() const { return data.empty(); }
    string top() const { return data.empty() ? string() : data.back(); }
};

int main() {
    Node* head = nullptr;
    Stack st;
    vector<string> visits = {"Google", "Facebook", "Twitter", "LinkedIn", "Instagram"};
    for (const string& s : visits) {
        addFront(head, s);
        st.push(s);
    }
    for (int i = 0; i < 2; ++i) {
        if (!st.empty()) st.pop();
        removeFront(head);
    }
    if (head) cout << head->url << endl;
    else cout << "No page" << endl;
    return 0;
}