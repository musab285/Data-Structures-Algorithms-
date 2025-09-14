// Write a Program that ask user to enter 10 elements and finds the 4 minimum elements
// from given array using selection Sort.

#include <iostream>
using namespace std;

int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "ENTER ELEMENT #" << i + 1 << ": " << endl;
        cin >> arr[i];
    }
    for (int i = 0; i < 4; i++)
    {
        int mn = i;
        for (int j = i + 1; j < 10; j++)
        {
            if(arr[mn]>arr[j]) mn = j;
        }
        int tmp = arr[i]; 
        arr[i] = arr[mn]; 
        arr[mn] = tmp; 
        cout<<"MIN ELEMENT NO #"<<i+1<<": "<<arr[i]<<endl; 
    }
}