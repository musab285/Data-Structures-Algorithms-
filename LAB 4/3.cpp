// Given an array of strings arr[]. Sort given strings using Bubble Sort and display the
// sorted array.
// Input: string arr[] = {"banana", "apple", "cherry", "date", "grape"};
// Output: apple banana cherry date grape

#include <iostream>
using namespace std;

int main()
{
    string arr[5] = {"banana", "apple", "cherry", "date", "grape"};
    bool swp = true;
    int i = 0;
    while (i < 4 && swp)
    {
        swp = false;
        int j = 0;
        for (int j = 0; j < 4 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                string tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                swp = true;
            }
        }
    }
    for (int i = 0; i < 5; i++)
        cout << "INDEX # " << i << ": " << arr[i] << endl;
}