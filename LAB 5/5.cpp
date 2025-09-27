// Imagine you are working on a scientific application that involves processing a multi-
// dimensional array. You need to implement a function to calculate the sum of all elements in the
// array, which may contain nested arrays (creating a multi-dimensional structure using a jagged
// array).
// Write a C++ function int recursiveArraySum(int* arr[], int sizes[], int dim) that calculates the sum
// of all elements in a multi-dimensional array represented by a jagged array. The function should
// work for arrays containing nested arrays, and sizes is an array that contains the sizes of each
// dimension, and dim is the current dimension being processed.

#include <iostream>
using namespace std;

int recSum(int *arr[], int sizes[], int dim, int sm)
{
    if (dim == -1)
    {
        return sm;
    }
    for (int i = 0; i < sizes[dim]; i++)
    {
        sm += arr[dim][i];
    }
    return recSum(arr, sizes, dim - 1, sm);
}

int main()
{
    int dim = 3;
    int sizes[] = {1, 2, 3};
    int **arr = new int *[dim];
    int cnt = 1;
    for (int i = 0; i < dim; i++)
    {
        arr[i] = new int[sizes[i]];
        for (int j = 0; j < sizes[i]; j++)
        {
            arr[i][j] = cnt++;
        }
    }

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < sizes[i]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "SUM: " << recSum(arr, sizes, dim - 1, 0) << endl;
}