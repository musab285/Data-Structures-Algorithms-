// Given an array of distinct integers, find using hashing if there are two pairs (a, b) and (c, d) such that
// a+b = c+d, and a, b, c, and d are distinct elements. If there are multiple answers, then print any of
// them.
// Input: {3, 4, 7, 1, 2, 9, 8}
// Output: (3, 8) and (4, 7)
// Explanation: 3+8 = 4+7
// Input: {3, 4, 7, 1, 12, 9};
// Output: (4, 12) and (7, 9)
// Explanation: 4+12 = 7+9
// Input: {65, 30, 7, 90, 1, 9, 8};
// Output: No pairs found


#include <iostream>
using namespace std;

struct PairSum {
    int a, b; 
    bool used;
};

int main() {
    int arr[] = {3, 4, 7, 1, 2, 9, 8}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    PairSum hashTable[1000];
    for (int i = 0; i < 1000; i++)
        hashTable[i].used = false;

    bool found = false;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            int sum = arr[i] + arr[j];
            if (hashTable[sum].used) {
                int a = hashTable[sum].a;
                int b = hashTable[sum].b;
                if (a != arr[i] && a != arr[j] && b != arr[i] && b != arr[j]) {
                    cout << "(" << a << ", " << b << ") and ("
                         << arr[i] << ", " << arr[j] << ")" << endl;
                    found = true;
                    break;
                }
            }
            else {
                hashTable[sum].a = arr[i];
                hashTable[sum].b = arr[j];
                hashTable[sum].used = true;
            }
        }
        if (found) break;
    }

    if (!found)
        cout << "No pairs found" << endl;

    return 0;
}
