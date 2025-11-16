#include <iostream>
#include <vector>
using namespace std;

bool isHeap(vector<int>& a, int i) {
    int n = a.size();
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[i] < a[l]) return false;
    if (r < n && a[i] < a[r]) return false;

    bool left_ok = (l >= n) || isHeap(a, l);
    bool right_ok = (r >= n) || isHeap(a, r);

    return left_ok && right_ok;
}

void heapify(vector<int>& a, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;

    if (largest != i) {
        int t = a[i]; a[i] = a[largest]; a[largest] = t;
        heapify(a, n, largest);
    }
}

void heapSort(vector<int>& a) {
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);
    for (int i = n - 1; i >= 0; i--) {
        int t = a[0]; a[0] = a[i]; a[i] = t;
        heapify(a, i, 0);
    }
}

int main() {
    vector<int> arr = {8,7,6,5,4};

    if (isHeap(arr, 0)) cout << "It is a binary heap\n";
    else cout << "Not a heap\n";

    heapSort(arr);

    for (int x : arr) cout << x << " ";
}