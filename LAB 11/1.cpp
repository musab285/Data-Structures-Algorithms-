// Suppose you are working on a program that needs to store a large number of strings, with the possibility of
// duplicate strings. You decide to use chain hashing to efficiently store and retrieve the strings, but you want
// to ensure that collisions are avoided as much as possible. Your hash function simply takes the sum of the
// ASCII values of the characters in the string and returns the remainder after dividing by the number of
// buckets. You decide to implement the hash table using a linked list for each bucket.

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string d) {
        data = d;
        next = NULL;
    }
};

class HashTable {
private:
    int buckets;
    Node** table;

public:
    HashTable(int b) {
        buckets = b;
        table = new Node*[buckets];
        for (int i = 0; i < buckets; i++)
            table[i] = NULL;
    }

    // Hash Function
    int hashFunction(string s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            sum += int(s[i]);
        }
        return sum % buckets;
    }

    // Insert Function
    void insert(string s) {
        int index = hashFunction(s);
        Node* newNode = new Node(s);

        // Insert at beginning of chain
        newNode->next = table[index];
        table[index] = newNode;

        cout << "Inserted \"" << s << "\" at bucket " << index << endl;
    }

    // Search Function
    bool search(string s) {
        int index = hashFunction(s);
        Node* curr = table[index];

        while (curr != NULL) {
            if (curr->data == s) return true;
            curr = curr->next;
        }

        return false;
    }

    // Display Hash Table
    void display() {
        cout << "\n--- HASH TABLE ---\n";
        for (int i = 0; i < buckets; i++) {
            cout << "Bucket " << i << ": ";
            Node* curr = table[i];
            while (curr != NULL) {
                cout << curr->data << " -> ";
                curr = curr->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    int buckets;
    cout << "Enter number of buckets: ";
    cin >> buckets;

    HashTable ht(buckets);

    int n;
    cout << "How many strings do you want to insert? ";
    cin >> n;

    cout << "\nEnter strings:\n";
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ht.insert(s);
    }

    ht.display();

    cout << "\nSearch a string: ";
    string key;
    cin >> key;

    if (ht.search(key))
        cout << "\"" << key << "\" found in hash table.\n";
    else
        cout << "\"" << key << "\" NOT found.\n";

    return 0;
}
