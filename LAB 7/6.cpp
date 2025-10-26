// Task 6:

// You have been given two unsorted arrays, arr1 and arr2, each containing 10 integers. You need to
// combine the two arrays into a single sorted array using either Radix Sort or Merge Sort.
//  Write a C++ program to combine arr1 and arr2 using Radix Sort and print the sorted array.
//  Write a C++ program to combine arr1 and arr2 using Merge Sort and print the sorted array.

#include <iostream>
using namespace std;

int maxInArray(int a[], int n){
    if(n <= 0) return 0;
    int mx = a[0];
    for(int i = 1; i < n; ++i) if(a[i] > mx) mx = a[i];
    return mx;
}

void radixSortNonNeg(int in[], int n, int out[]){
    if(n <= 0) return;
    int tmp[20];
    for(int i = 0; i < n; ++i) tmp[i] = in[i];
    int mx = maxInArray(tmp, n);
    for(int exp = 1; mx/exp > 0; exp *= 10){
        int output[20];
        int count[10] = {0};
        for(int i = 0; i < n; ++i) count[(tmp[i] / exp) % 10]++;
        for(int i = 1; i < 10; ++i) count[i] += count[i-1];
        for(int i = n - 1; i >= 0; --i){
            int d = (tmp[i] / exp) % 10;
            output[--count[d]] = tmp[i];
        }
        for(int i = 0; i < n; ++i) tmp[i] = output[i];
    }
    for(int i = 0; i < n; ++i) out[i] = tmp[i];
}

void radixSort(int a[], int n, int out[]){
    int pos[20], posN = 0;
    int negAbs[20], negN = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] >= 0) pos[posN++] = a[i];
        else negAbs[negN++] = (int)(-(long long)a[i]);
    }
    int posSorted[20], negSorted[20];
    radixSortNonNeg(pos, posN, posSorted);
    radixSortNonNeg(negAbs, negN, negSorted);
    int idx = 0;
    // negatives: negAbs sorted ascending; reverse and negate to get proper negative order
    for(int i = negN - 1; i >= 0; --i) out[idx++] = -negSorted[i];
    for(int i = 0; i < posN; ++i) out[idx++] = posSorted[i];
}

void mergeVectors(int a[], int temp[], int l, int m, int r){
    int i = l, j = m + 1, k = l;
    while(i <= m && j <= r){
        if(a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while(i <= m) temp[k++] = a[i++];
    while(j <= r) temp[k++] = a[j++];
    for(int idx = l; idx <= r; ++idx) a[idx] = temp[idx];
}

void mergeSortRec(int a[], int temp[], int l, int r){
    if(l >= r) return;
    int m = l + (r - l) / 2;
    mergeSortRec(a, temp, l, m);
    mergeSortRec(a, temp, m + 1, r);
    mergeVectors(a, temp, l, m, r);
}

void mergeSort(int a[], int n, int out[]){
    if(n <= 0) return;
    int tmp[20];
    for(int i = 0; i < n; ++i) tmp[i] = a[i];
    int temp[20];
    mergeSortRec(tmp, temp, 0, n - 1);
    for(int i = 0; i < n; ++i) out[i] = tmp[i];
}

int main(){
    int arr1[10] = {34, -2, 45, 29, 8, 0, -17, 102, 3, 56};
    int arr2[10] = {7, -50, 23, 11, -1, 90, 12, -99, 5, 44};
    int combined[20];
    int n1 = 10, n2 = 10, n = n1 + n2;
    for(int i = 0; i < n1; ++i) combined[i] = arr1[i];
    for(int i = 0; i < n2; ++i) combined[n1 + i] = arr2[i];

    int rsorted[20], msorted[20];
    radixSort(combined, n, rsorted);
    mergeSort(combined, n, msorted);

    cout << "Radix Sort: ";
    for(int i = 0; i < n; ++i){
        if(i) cout << ' ';
        cout << rsorted[i];
    }
    cout << '\n';

    cout << "Merge Sort: ";
    for(int i = 0; i < n; ++i){
        if(i) cout << ' ';
        cout << msorted[i];
    }
    cout << '\n';
    return 0;
}