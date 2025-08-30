// You are tasked with developing a program to manage and display the Grade Point Average
// (GPA) for the core courses offered in the first semester of four departments: Software
// Engineering (SE), Artificial Intelligence (AI), Computer Science (CS), and Data Science (DS).
// Each department offers a distinct number of core courses for this semester: SE has 3 core
// courses, AI has 4 core courses, CS has 2 core courses, and DS has 1 core course. To efficiently
// store and present this data, which type of array structure would you employ? implement a
// solution using the chosen array structure to display the GPAs of the core courses for each
// department.

#include <iostream>
using namespace std;

int main(){
    string record[4] = {"SE", "AI", "CS", "DS"};
    float **gpa = new float*[4];
    gpa[0] = new float[3]; 
    gpa[1] = new float[4];
    gpa[2] = new float[2];
    gpa[3] = new float[1];

    gpa[0][0] = 3.5; gpa[0][1] = 3.7; gpa[0][2] = 3.9;
    gpa[1][0] = 3.6; gpa[1][1] = 3.8; gpa[1][2] = 3.4; gpa[1][3] = 3.9;
    gpa[2][0] = 3.2; gpa[2][1] = 3.5;
    gpa[3][0] = 3.8;

    for (int i = 0; i < 4; i++) {
        cout << "Department: " << record[i] << endl;
        cout << "Core Course GPAs: ";
        for (int j = 0; j < (i == 0 ? 3 : (i == 1 ? 4 : (i == 2 ? 2 : 1))); j++) {
            cout << gpa[i][j];
            if (j < (i == 0 ? 3 : (i == 1 ? 4 : (i == 2 ? 2 : 1))) - 1)
                cout << ", ";
        }
        cout << endl << endl;
    }
    for (int i = 0; i < 4; i++) {
        delete[] gpa[i];
    }
    delete[] gpa;

    return 0;
}