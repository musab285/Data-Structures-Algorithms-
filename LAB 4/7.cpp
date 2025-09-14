// From array mentioned below find the following names and their index using binary
// search as well as linear search and count the number of steps on each finding element by using
// both techniques and analyze which technique is getting more time:
// • Aftab
// • Rizwan
// • Tariq

#include <iostream>
using namespace std;

void binSearch(string arr[], int n, string ky)
{
    cout << "BINARY SEARCH FOR " << ky << ": " << endl;
    int lft = 0, rght = n - 1, cnt = 0;
    while (lft <= rght)
    {
        int md = lft + ((rght - lft) / 2);
        cnt++;
        if (arr[md] == ky)
        {
            cout << ky << " FOUND AT INDEX # " << md << endl
                 << "NO OF OPERATIONS: " << cnt << endl;
            return;
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
    cout << ky << " NOT FOUND" << endl
         << "NO OF OPERATIONS: " << cnt << endl;
    return;
}

void linSearch(string arr[], int n, string ky)
{
    cout << "LINEAR SEARCH FOR " << ky << ": " << endl;
    int cnt = 0;
    for (int i = 0; i < n; i++, ++cnt)
    {
        if (arr[i] == ky)
        {
            cout << ky << " FOUND AT INDEX # " << i << endl
                 << "NO OF OPERATIONS: " << cnt << endl;
            return;
        }
    }
    cout << ky << " NOT FOUND" << endl
         << "NO OF OPERATIONS: " << cnt << endl;
    return;
}

int main()
{
    string arr[] = {"Ahmed", "Ali", "Basit", "Karim", "Rizwan", "Sarwar", "Tariq", "Taufiq", "Yasin", "Zulfiqar"};
    binSearch(arr, 10, "Aftab");
    linSearch(arr, 10, "Aftab");
    binSearch(arr, 10, "Rizwan");
    linSearch(arr, 10, "Rizwan");
    binSearch(arr, 10, "Tariq");
    linSearch(arr, 10, "Tariq");
}