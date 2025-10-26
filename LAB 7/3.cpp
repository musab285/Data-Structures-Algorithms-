#include <iostream>
#include <string>
using namespace std;

struct Runner {
    string name;
    int time;
};

void merge(Runner arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    Runner* L = new Runner[n1];
    Runner* R = new Runner[n2];
    for (int i = 0; i < n1; ++i) L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].time <= R[j].time) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    delete[] L;
    delete[] R;
}

void mergeSort(Runner arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    const int N = 10;
    Runner arr[N];
    for (int i = 0; i < N; ++i) {
        cout << "Enter name and finish time (seconds) for participant " << i + 1 << ": ";
        cin >> arr[i].name >> arr[i].time;
    }
    mergeSort(arr, 0, N - 1);
    cout << "Top 5 fastest runners:\n";
    for (int i = 0; i < 5; ++i) {
        cout << i + 1 << ". " << arr[i].name << " " << arr[i].time << "s\n";
    }
    return 0;
}
