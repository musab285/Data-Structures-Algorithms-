#include <iostream>
#include <algorithm>
using namespace std;

int kthLargest(int arr[], int n, int K) {
    sort(arr, arr + n, greater<int>());
    return arr[K - 1];
}

int main() {
    int arr1[] = {1, 23, 12, 9, 30, 2, 50};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int K1 = 3;
    cout << kthLargest(arr1, n1, K1) << endl;

    int arr2[] = {12, 3, 5, 7, 19};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int K2 = 2;
    cout << kthLargest(arr2, n2, K2) << endl;

    return 0;
}