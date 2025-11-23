// Some ABC university students want to develop an ASCII code-based dictionary app for their Final Year
// Project. This app should allow the users to perform the following operations:
// a) Add_Record () This function will take a string input from user and add into the dictionary. For adding
// the string user will use a unique hash function k MOD 100 (table size must be 100, for k user will calculate
// the SUM of ASCII character of that word).
// b) Word_Search () User will only pass a single string. If string is not available then generate an error
// message.
// c) Print_Dictionary () Users can also display the complete dictionary.
// Note: Use Separate Chaining in case of collisions.




#include <iostream>
#include <string>
using namespace std;

struct Node {
    string word;
    Node *next;
};

int hashFunction(string s) {
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
        sum += int(s[i]);
    return sum % 100;
}

void addRecord(Node* table[]) {
    string w;
    cout << "ENTER WORD TO ADD: ";
    cin >> w;

    int idx = hashFunction(w);

    Node* newNode = new Node;
    newNode->word = w;
    newNode->next = table[idx];
    table[idx] = newNode;

    cout << "WORD ADDED AT INDEX " << idx << endl;
}

void searchWord(Node* table[]) {
    string w;
    cout << "ENTER WORD TO SEARCH: ";
    cin >> w;

    int idx = hashFunction(w);

    Node* curr = table[idx];
    while (curr != NULL) {
        if (curr->word == w) {
            cout << "WORD FOUND AT INDEX " << idx << endl;
            return;
        }
        curr = curr->next;
    }

    cout << "ERROR! WORD NOT FOUND." << endl;
}

void printDictionary(Node* table[]) {
    cout << "\n--- DICTIONARY CONTENTS ---\n";
    for (int i = 0; i < 100; i++) {
        cout << "INDEX " << i << ": ";
        Node* curr = table[i];

        if (curr == NULL) {
            cout << "EMPTY\n";
            continue;
        }

        while (curr != NULL) {
            cout << curr->word << " -> ";
            curr = curr->next;
        }
        cout << "NULL\n";
    }
}

int main() {
    Node* table[100];
    
    // initialize table with NULL
    for (int i = 0; i < 100; i++)
        table[i] = NULL;

    int choice;

    do {
        cout << "\n1. Add Record\n";
        cout << "2. Search Word\n";
        cout << "3. Print Dictionary\n";
        cout << "4. Exit\n";
        cout << "ENTER CHOICE: ";
        cin >> choice;

        if (choice == 1)
            addRecord(table);
        else if (choice == 2)
            searchWord(table);
        else if (choice == 3)
            printDictionary(table);
        else if (choice != 4)
            cout << "INVALID CHOICE!\n";

    } while (choice != 4);

    return 0;
}
