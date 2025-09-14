// Given an unsorted array that may contain duplicates. Write a function that returns true
// if the array contains duplicates.

#include <iostream>
using namespace std;

bool chck_dup(int arr[], int n)
{
    bool swp = true;
    int i = 0;
    while (i < n && swp)
    {
        swp = false;
        int j = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                swp = true;
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
            return true;
    }
    return false;
}

int main()
{
    int arr[5] = {1, 3, 4, 1, 5};
    if (chck_dup(arr, 5))
        cout << "DUPLICATE FOUND";
    else
        cout << "DUPLICATE NOT FOUND";
}