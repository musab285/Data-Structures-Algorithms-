// Task#4
// Write a program that creates a 2D array of 5x5 values of type Boolean. Suppose
// indices represent people and the value at row i, column j of a 2D array is true just in
// case i and j are friends and false otherwise. You can use initializer list to instantiate
// and initialize your array to represent the following configuration: (* means “friends”)
// i/j 0 1 2 3 4
// 0 * * *
// 1 * * *
// 2 *
// 3 * *
// 4 * * *
// Write a method to check whether two people have a common friend. For example, in the
// example above, 0 and 4 are both friends with 3 (so they have a common friend), whereas 1 and 2
// have no common friends.



#include<iostream>
using namespace std;

class Matrix{
    char **matrix;
    int rows,cols;

    public:
    Matrix()
    {
        rows=5;
        cols=5;

        matrix=new char*[rows];
        for(int i=0;i<rows;i++)
        {
            matrix[i]=new char[cols];
        }

        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                char a;
                cout<<"Enter * for friendship of person "<<i<<" with person "<<j<<" otherwise enter 0 "<<endl;
                cin>>a;
                matrix[i][j]=a;

            }
        }
    }
    
    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    } 

    bool check(int friend1,int friend2)
    {
        for(int i=0;i<5;i++)
        {
            if(matrix[friend1][i]==matrix[friend2][i])return true;
        }
        return false;

    }

};
int main() {
    Matrix m;

    int friend1, friend2;
    cout << "Enter index of first person ";
    cin >> friend1;
    cout << "Enter index of second person ";
    cin >> friend2;

 if (m.check(friend1, friend2)) {
        cout << "They have a common friend." << endl;
    } else {
        cout << "They do not have any common friends." << endl;
    }

    return 0;
}