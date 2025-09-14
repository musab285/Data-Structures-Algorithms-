// Given an array with birth years of children born in 2022, 2023, and 2024, the task is to
// sort the array so that all children born in 2022 come first, followed by those born in 2023, and
// finally those born in 2024.
// Input: {2022, 2023, 2024, 2022, 2023, 2024}
// Output: {2022, 2022, 2023, 2023, 2024, 2024}
// Explanation: {2022, 2022, 2023, 2023, 2024, 2024} shows that all the 2022 birth years come
// first, followed by the 2023 , and then all the 2024 birth years at the end.

#include <iostream>
using namespace std;

int main()
{
    int arr[6] = {2022, 2023, 2024, 2022, 2023, 2024};
    bool swp = true;
    int i = 0;
    while (i < 6 && swp)
    {
        swp = false;
        int j = 0;
        for (int j = 0; j < 5 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                swp = true;
            }
        }
    }
    for (int i = 0; i < 6; i++)
        cout << "INDEX # " << i << ": " << arr[i] << endl;
}