// Task#1: Suppose you are building an application that stores student records in an AVL tree
// based on their roll number. You want to insert a new student with roll number 15 into the AVL
// tree, and you want to ensure that the tree is balanced using left rotation. Assuming the AVL
// tree is already populated with the following student records:
// Student 1 with roll number 10
// Student 2 with roll number 20
// Student 3 with roll number 30
// Student 4 with roll number 40
// Student 5 with roll number 50

//  Walk me through the process of inserting the new student record with roll number 15
// into the AVL tree.

//  After inserting the new student record, what will be the height of the AVL tree?
//  Using the left rotation operation, show the resulting AVL tree after inserting the new
// student record.

#include <iostream>
using namespace std;

struct Node {
    int roll;
    Node* l;
    Node* r;
    int h;
};

int height(Node* n) {
    return n ? n->h : 0;
}

int getBal(Node* n) {
    return n ? height(n->l) - height(n->r) : 0;
}

Node* newNode(int v) {
    Node* n = new Node;
    n->roll = v;
    n->l = n->r = NULL;
    n->h = 1;
    return n;
}

Node* leftRotate(Node* x) {
    Node* y = x->r;
    Node* t2 = y->l;
    y->l = x;
    x->r = t2;
    x->h = max(height(x->l), height(x->r)) + 1;
    y->h = max(height(y->l), height(y->r)) + 1;
    return y;
}

Node* rightRotate(Node* y) {
    Node* x = y->l;
    Node* t2 = x->r;
    x->r = y;
    y->l = t2;
    y->h = max(height(y->l), height(y->r)) + 1;
    x->h = max(height(x->l), height(x->r)) + 1;
    return x;
}

Node* insert(Node* root, int v) {
    if (!root) return newNode(v);
    if (v < root->roll) root->l = insert(root->l, v);
    else if (v > root->roll) root->r = insert(root->r, v);
    else return root;
    root->h = 1 + max(height(root->l), height(root->r));
    int b = getBal(root);
    if (b > 1 && v < root->l->roll) return rightRotate(root);
    if (b < -1 && v > root->r->roll) return leftRotate(root);
    if (b > 1 && v > root->l->roll) {
        root->l = leftRotate(root->l);
        return rightRotate(root);
    }
    if (b < -1 && v < root->r->roll) {
        root->r = rightRotate(root->r);
        return leftRotate(root);
    }
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->l);
    cout << root->roll << " ";
    inorder(root->r);
}

int main() {
    Node* root = NULL;
    int arr[5] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) root = insert(root, arr[i]);
    cout << "AVL BEFORE INSERTION: ";
    inorder(root);
    cout << endl;
    root = insert(root, 15);
    cout << "AVL AFTER INSERTION OF 15: ";
    inorder(root);
    cout << endl;
    cout << "HEIGHT OF AVL: " << height(root) << endl;
}
`
