// You're developing a program to manage a seating chart for a conference held in a hall with
// multiple rows of seats. Each row has a different seat capacity. To efficiently handle the seating
// arrangements, you decide to use a dynamic array. Implement a C++ code that allocates memory
// for the seating chart and allows attendees' names to be inputted for each seat. Choose and
// implement the appropriate type of dynamic array for this scenario.

#include <iostream>
using namespace std;

int main(){
    int row, col; 
    cout<<"Enter number of rows: "; cin>>row; 
    string **seats = new string*[row];
    for (int i = 0; i < row; i++) {
        cout << "Enter number of seats in row " << i + 1 << ": ";
        cin >> col;
        seats[i] = new string[col];
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << "Enter name for seat [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> seats[i][j];
        }
    }
    cout << "\nSeating Chart:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << seats[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < row; i++) {
        delete[] seats[i];
    }
    delete[] seats;

    return 0;
}
