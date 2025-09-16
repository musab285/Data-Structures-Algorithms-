#include<iostream>
using namespace std; 

bool isSafe(int** arr, int x, int y, int n) {
    if (x < n && y < n && arr[x][y] == 1) {
        return true;
    }
    return false;
}

bool ratInMaze(int** arr, int x, int y, int n, int** solArr) {
    if (!isSafe(arr, x, y, n) || solArr[x][y] == 1) {
        return false;
    }

    if ((x == 2) && (y == 0)) { 
        solArr[x][y] = 1;
        return true;
    }

    solArr[x][y] = 1;

    if (x < n - 1 && ratInMaze(arr, x + 1, y, n, solArr)) {
        return true;
    }
    if (y < n - 1 && ratInMaze(arr, x, y + 1, n, solArr)) {
        return true;
    }
    if (x > 0 && ratInMaze(arr, x - 1, y, n, solArr)) {
        return true;
    }
    if (y > 0 && ratInMaze(arr, x, y - 1, n, solArr)) {
        return true;
    }

    solArr[x][y] = 0;
    return false;
}

int main(){
    int arr[4][4] = {{1,1,1,1}, {0,0, 0, 1}, {1,1,0,1}, {1,1,1,1}};
    int **solArr;
    int **nwarr; 
    solArr = new int * [4]; 
    nwarr = new int * [4]; 
    for(int i = 0; i<4; i++){
        solArr[i] = new int [4]; 
        nwarr[i] = new int [4];
        for(int j = 0 ; j<4; j++){
            solArr[i][j] = 0; 
            nwarr[i][j] = arr[i][j];
        }
    }
    ratInMaze(nwarr, 0, 0,4, solArr);
    for(int i = 0 ; i<4; i++){
        for(int j = 0 ; j<4; j++) cout<<solArr[i][j]<<" "; 
        cout<<endl; 
    } 
    
}