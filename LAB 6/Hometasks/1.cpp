// Task 1: Suppose you are building a program to manage a to-do list for a busy professional. You decide
// to use a stack to keep track of the items on the list. Write a code snippet that demonstrates how you
// would add a new item to the top of the stack, check if the stack is empty, and remove the top item
// from the stack.

#include <iostream>
#include <string>

using namespace std;

template<typename T>
class SimpleStack {
    T* data;
    size_t sz;
    size_t cap;

    void grow() {
        size_t newCap = (cap == 0) ? 4 : cap * 2;
        T* newData = new T[newCap];
        for (size_t i = 0; i < sz; ++i) newData[i] = data[i];
        delete[] data;
        data = newData;
        cap = newCap;
    }

public:
    SimpleStack(): data(nullptr), sz(0), cap(0) {}
    ~SimpleStack() { delete[] data; }

    SimpleStack(const SimpleStack& other): data(nullptr), sz(other.sz), cap(other.cap) {
        if (cap) {
            data = new T[cap];
            for (size_t i = 0; i < sz; ++i) data[i] = other.data[i];
        }
    }
    SimpleStack& operator=(const SimpleStack& other) {
        if (this == &other) return *this;
        delete[] data;
        sz = other.sz; cap = other.cap;
        data = (cap ? new T[cap] : nullptr);
        for (size_t i = 0; i < sz; ++i) data[i] = other.data[i];
        return *this;
    }

    void push(const T& value) {
        if (sz == cap) grow();
        data[sz++] = value;
    }
    bool empty() const { return sz == 0; }
    const T& top() const { return data[sz - 1]; }
    void pop() { if (sz) --sz; }
};

int main() {
    SimpleStack<string> todo;

    todo.push("Prepare project report");

    cout << "Stack empty? " << (todo.empty() ? "Yes" : "No") << endl;

    if (!todo.empty()) {
        cout << "Top item: " << todo.top() << endl;
        todo.pop();
        cout << "Removed top item.\n";
    }

    cout << "Stack empty after pop? " << (todo.empty() ? "Yes" : "No") << endl;
    return 0;
}
