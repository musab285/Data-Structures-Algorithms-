// Implement a C++ class StudentHashTable to manage student records in a hash table with a size of 15. Use
// quadratic probing for collision resolution with the formula (index + attempt^2) % table size.Implement the
// function InsertRecord that takes a student&#39;s roll number and name, inserting the record into the hash table
// using quadratic probing.Implement the function SearchRecord that takes a roll number, searches for the
// corresponding record using quadratic probing, and prints the student&#39;s name if found; otherwise, print a
// &quot;Record not found&quot; message.

#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    bool occupied;
    Student() {
        roll = -1;
        name = "";
        occupied = false;
    }
};

class StudentHashTable {
private:
    Student table[15];

    int hashFunction(int r) {
        return r % 15;
    }

public:
    void InsertRecord(int r, string n) {
        int idx = hashFunction(r);
        int attempt = 0;

        while (attempt < 15) {
            int newIdx = (idx + attempt * attempt) % 15;

            if (!table[newIdx].occupied) {
                table[newIdx].roll = r;
                table[newIdx].name = n;
                table[newIdx].occupied = true;
                return;
            }
            attempt++;
        }
    }

    void SearchRecord(int r) {
        int idx = hashFunction(r);
        int attempt = 0;

        while (attempt < 15) {
            int newIdx = (idx + attempt * attempt) % 15;

            if (table[newIdx].occupied && table[newIdx].roll == r) {
                cout << table[newIdx].name << endl;
                return;
            }
            attempt++;
        }

        cout << "Record not found" << endl;
    }
};

int main() {
    StudentHashTable ht;
    ht.InsertRecord(10, "Ali");
    ht.InsertRecord(25, "Sara");
    ht.InsertRecord(40, "Bilal");
    ht.SearchRecord(25);
    ht.SearchRecord(99);
    return 0;
}
