// Task 7:
// In the quick sort algorithm, the selection of a pivot element is of utmost importance. There are
// different ways to select the pivot element. Your task is to implement quick sort using the following
// pivot selection techniques and count the number of comparisons of each approach:
// Note: The implementation should be in-place.
//  Select the first element as pivot.
//  Select any random element as pivot
//  Select middle element as pivot
//  Use median approach for pivot selection
//  Apply quick sort on list (Use any pivot selection approach)
// After applying all the above approaches, evaluate the efficiency of each pivot selection technique,
// we count the number of comparisons made during partitioning.
// Note: Apply the quick sort on different input arrays (e.g., sorted, reverse-sorted, random) to see
// how each pivot strategy performs.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int comparisons;

int partitionFirst(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1, j = high;
    while (true) {
        while (i <= high && arr[i] <= pivot) { i++; comparisons++; }
        while (j >= low && arr[j] > pivot) { j--; comparisons++; }
        if (i >= j) break;
        swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

int partitionMiddle(int arr[], int low, int high) {
    int mid = (low + high) / 2;
    swap(arr[low], arr[mid]);
    return partitionFirst(arr, low, high);
}

int partitionRandom(int arr[], int low, int high) {
    int randomPivot = low + rand() % (high - low + 1);
    swap(arr[low], arr[randomPivot]);
    return partitionFirst(arr, low, high);
}

int partitionMedian(int arr[], int low, int high) {
    int mid = (low + high) / 2;
    int a = arr[low], b = arr[mid], c = arr[high];
    int median;
    if ((a > b) != (a > c)) median = low;
    else if ((b > a) != (b > c)) median = mid;
    else median = high;
    swap(arr[low], arr[median]);
    return partitionFirst(arr, low, high);
}

void quickSort(int arr[], int low, int high, int type) {
    if (low < high) {
        int p;
        if (type == 1) p = partitionFirst(arr, low, high);
        else if (type == 2) p = partitionRandom(arr, low, high);
        else if (type == 3) p = partitionMiddle(arr, low, high);
        else p = partitionMedian(arr, low, high);
        quickSort(arr, low, p - 1, type);
        quickSort(arr, p + 1, high, type);
    }
}

void run(int arr[], int n, int type) {
    comparisons = 0;
    quickSort(arr, 0, n - 1, type);
    cout << comparisons << endl;
}

int main() {
    srand(time(0));
    int n = 10;
    int arr1[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr3[10] = {5, 1, 9, 3, 7, 2, 10, 6, 8, 4};

    cout << "Reverse-sorted array - comparisons by pivot" << endl;
    int t1[10], t2[10], t3[10], t4[10];
    copy(begin(arr1), end(arr1), begin(t1));
    copy(begin(arr1), end(arr1), begin(t2));
    copy(begin(arr1), end(arr1), begin(t3));
    copy(begin(arr1), end(arr1), begin(t4));
    cout << "Pivot (first): "; run(t1, n, 1);
    cout << "Pivot (random): "; run(t2, n, 2);
    cout << "Pivot (middle): "; run(t3, n, 3);
    cout << "Pivot (median-of-three): "; run(t4, n, 4);

    cout << "Sorted array - comparisons by pivot" << endl;
    copy(begin(arr2), end(arr2), begin(t1));
    copy(begin(arr2), end(arr2), begin(t2));
    copy(begin(arr2), end(arr2), begin(t3));
    copy(begin(arr2), end(arr2), begin(t4));
    cout << "Pivot (first): "; run(t1, n, 1);
    cout << "Pivot (random): "; run(t2, n, 2);
    cout << "Pivot (middle): "; run(t3, n, 3);
    cout << "Pivot (median-of-three): "; run(t4, n, 4);

    cout << "=== Random array - comparisons by pivot ===" << endl;
    copy(begin(arr3), end(arr3), begin(t1));
    copy(begin(arr3), end(arr3), begin(t2));
    copy(begin(arr3), end(arr3), begin(t3));
    copy(begin(arr3), end(arr3), begin(t4));
    cout << "Pivot (first): "; run(t1, n, 1);
    cout << "Pivot (random): "; run(t2, n, 2);
    cout << "Pivot (middle): "; run(t3, n, 3);
    cout << "Pivot (median-of-three): "; run(t4, n, 4);
}