// Let arr[9] = { 20, 12, 15, 2, 10, 1, 13, 9, 5} now sort the array in such a way that
// maximum element must be at middle of the array and rest of array must be sorted in ascending
// order do this using insertion sort.

#include <iostream>
using namespace std;

int main()
{
    int arr[9] = {20, 12, 15, 2, 10, 1, 13, 9, 5};
    for (int i = 1; i < 9; i++)
    {
        int ky = arr[i];
        int j = i - 1;
        while (j >= 0 && ky < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = ky;
    }
    int md = 4;
    int tmp = arr[8];
    arr[8] = arr[md];
    arr[md] = tmp;
    for (int i = 6; i < 9; i++)
    {
        int ky = arr[i];
        int j = i - 1;
        while (j >= 5 && ky < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = ky;
    }
    for (int i = 0; i < 9; i++)
        cout << "INDEX # " << i << ": " << arr[i] << endl;
}