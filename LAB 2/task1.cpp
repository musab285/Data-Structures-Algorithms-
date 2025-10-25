// You are tasked with implementing a dynamic matrix class in C++ that supports the following
// operations: Dynamic Matrix Creation: Create a dynamic 2D array (matrix) with rows and columns
// specified by the user. Matrix Resizing: Implement a method to resize the matrix. The new size
// should be provided as input (new rows and columns). If the new size is larger, initialize the new
// elements with a given value. If the new size is smaller, truncate the matrix. Matrix Transposition:
// Implement a method to transpose the matrix (rows become columns and vice versa). Matrix
// Printing: Implement a method to print the matrix. After add 2 to each odd index then print the
// array. Memory Deallocation: Ensure proper memory management, including deallocation of the
// dynamic matrix when no longer needed.

#include<iostream> 
using namespace std; 

class Matrix{ 
    int **mtrx;
    int row, col;

    public: 
    Matrix(int rw, int cl, int val):row(rw), col(cl){
        mtrx = new int*[rw]; 
        for(int i=0; i<rw; i++){
            mtrx[i] = new int[cl]; 
            for(int j=0; j<cl; j++){
                mtrx[i][j] = val; 
            }
        }
    }
    void resize(int rw, int cl , int val){
        int **temp; 
        temp = new int*[row]; 
        for(int i=0; i<row; i++){
            temp[i] = new int[col]; 
            for(int j=0; j<col; j++){
                temp[i][j] = mtrx[i][j]; 
            }
        }

        mtrx = new int*[rw]; 
        for(int i=0; i<rw; i++){
            mtrx[i] = new int[cl]; 
        }

        for(int i=0; i<row; i++){
            for(int j =0; j<col; j++){
                mtrx[i][j] = temp[i][j]; 
            }
        }
        if(rw>row){
            for(int i = 0; i<rw; i++){
                for(int j = 0; j<cl; j++){
                    mtrx[i][j] = val; 
                }
            }
        }
        row = rw; col = cl; 
    }
    void transpose(){
        if(row==col){
        int **temp; 
        temp = new int*[row]; 
        for(int i=0; i<row; i++){
            temp[i] = new int[col]; 
            for(int j=0; j<col; j++){
                temp[i][j] = mtrx[i][j]; 
            }
        }
        for(int i=0; i<row; i++){
            for(int j =0; j<col; j++){
                mtrx[j][i] = temp[i][j]; 
            }
        }
        }else{
            cout<<"CAN'T TRANSPOSE"<<endl; 
        }
    }
    void traverse(){
        for(int i=0; i<row; i++){
            for(int j =0; j<col; j++){
                cout<<mtrx[i][j]<<" "; 
            }
            cout<<endl; 
        }
    }
    void addtwo(){
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(j % 2 == 1){
                    mtrx[i][j] += 2;
                }
            }
        }
    }
}; 

int main(){
    Matrix mt(3, 3, 5); 
    mt.traverse(); 
    mt.addtwo(); 
    cout<<"After addition"<<endl ; 
    mt.traverse();
    mt.transpose(); 
    cout<<"Transpose"<<endl ; 
    mt.traverse(); 
    mt.resize(4,4, 7); 
    cout<<"After Resizing"<<endl ; 
    mt.traverse(); 
}