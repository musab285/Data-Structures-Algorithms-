// Task 5: Implement a Queue based approach where assume you are the cashier in a supermarket and
// you need to make checkouts. Customer ID’s Are 13,7,4,1,6,8,10. (Note: Use Arrays to accomplish this
// task with enqueue and dequeue)

#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int capacity;
    int frontIndex;
    int rearIndex;
    int count;
public:
    Queue(int size = 100) : capacity(size), frontIndex(0), rearIndex(-1), count(0) {
        arr = new int[capacity];
    }
    ~Queue() { delete[] arr; }
    bool isEmpty() { return count == 0; }
    bool isFull() { return count == capacity; }
    void enqueue(int x) {
        if (isFull()) return;
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = x;
        ++count;
    }
    int dequeue() {
        if (isEmpty()) return -1;
        int x = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        --count;
        return x;
    }
};

int main() {
    Queue q(10);
    int ids[] = {13, 7, 4, 1, 6, 8, 10};
    for (int id : ids) q.enqueue(id);
    while (!q.isEmpty()) {
        cout << q.dequeue();
        if (!q.isEmpty()) cout << ' ';
    }
    cout << '\n';
    return 0;
}