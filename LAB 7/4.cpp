// Task-4:
// Imagine you are working for a company that provides an online shopping platform. There are only 3
// products listed on the platform, and customers often search for products based on their price. Write a
// program in C++ that uses Quick sort to sort the products based on their price in ascending order.
// Define a class for each product that will store its name, price, description, and availability?

// Steps of Quick Sort:
//  Pivot Selection: Choose a pivot element.
//  Partitioning: Rearrange the array such that all elements smaller than the pivot are on the left,
// and all greater elements are on the right.
//  Recursion: Recursively apply the quick sort on the left and right halves of the array.
// The efficiency of Quick Sort depends on the pivot selection strategy.

#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    string name;
    double price;
    string description;
    bool available;
};

int partition(Product arr[], int low, int high) {
    double pivot = arr[high].price;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].price < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Product arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    Product p[3];
    for (int i = 0; i < 3; i++) {
        cout << "Enter product name: ";
        cin >> p[i].name;
        cout << "Enter price: ";
        cin >> p[i].price;
        cout << "Enter description: ";
        cin.ignore();
        getline(cin, p[i].description);
        cout << "Available (1 for yes, 0 for no): ";
        cin >> p[i].available;
    }

    quickSort(p, 0, 2);

    cout << "\nProducts sorted by price (ascending):\n";
    for (int i = 0; i < 3; i++)
        cout << p[i].name << " | " << p[i].price << " | " << p[i].description
             << " | " << (p[i].available ? "Available" : "Not Available") << endl;

}