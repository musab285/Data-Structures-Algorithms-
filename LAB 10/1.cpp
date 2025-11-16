#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
public:
    vector<int> h;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void swap(int &a, int &b) {
        int t = a; a = b; b = t;
    }

    void insertKey(int val) {
        h.push_back(val);
        int i = h.size() - 1;
        while (i != 0 && h[parent(i)] < h[i]) {
            swap(h[parent(i)], h[i]);
            i = parent(i);
        }
    }

    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < h.size() && h[l] > h[largest]) largest = l;
        if (r < h.size() && h[r] > h[largest]) largest = r;

        if (largest != i) {
            swap(h[i], h[largest]);
            heapify(largest);
        }
    }

    void update_key(int i, int new_val) {
        int old_val = h[i];
        h[i] = new_val;

        if (new_val > old_val) {
            while (i != 0 && h[parent(i)] < h[i]) {
                swap(h[parent(i)], h[i]);
                i = parent(i);
            }
        } else {
            heapify(i);
        }
    }

    void delete_key(int i) {
        update_key(i, INT_MAX);
        extractMax();
    }

    int extractMax() {
        if (h.size() == 0) return -1;
        if (h.size() == 1) {
            int root = h[0];
            h.pop_back();
            return root;
        }
        int root = h[0];
        h[0] = h.back();
        h.pop_back();
        heapify(0);
        return root;
    }

    void printHeap() {
        for (int x : h) cout << x << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap mh;
    mh.insertKey(8);
    mh.insertKey(7);
    mh.insertKey(6);
    mh.insertKey(5);
    mh.insertKey(4);

    mh.printHeap();
}