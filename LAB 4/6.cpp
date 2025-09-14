// Implement the array given in the heading of binary search topic, sort it and find the
// value corresponding to to your last two digits of the roll number
// (if its not in the array add a value somewhere in between the array) and find it via binary search.

#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {28, 4, 0, 2, 8};
    bool swp = true;
    int i = 0;
    while (i < 5 && swp)
    {
        swp = false;
        int j = 0;
        for (int j = 0; j < 4 - i; j++)
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
    int ky = 28;
    int lft = 0, rght = 4;
    while (lft <= rght)
    {
        int md = lft + ((rght - lft) / 2);
        if (arr[md] == ky)
        {
            break;
        }
        else if (arr[md] > ky)
        {
            rght = md - 1;
        }
        else
        {
            lft = md + 1;
        }
    }
    if (lft <= rght)
        cout << "FOUND";
    else
        cout << "NOT FOUND";
}