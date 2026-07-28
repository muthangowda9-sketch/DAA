#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Linear Search
int linear(vector<int> &numbers, int target)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == target)
            return i;
    }
    return -1;
}

// Binary Search
int binary(vector<int> &numbers, int target)
{
    int start = 0;
    int end = numbers.size() - 1;

    while (start <= end)
    {
        int middle = start + (end - start) / 2;

        if (numbers[middle] == target)
            return middle;

        if (numbers[middle] < target)
            start = middle + 1;
        else
            end = middle - 1;
    }

    return -1;
}

int main()
{
    const int SIZE = 100000;

    vector<int> data(SIZE);

    // Store sorted values
    for (int i = 0; i < SIZE; i++)
    {
        data[i] = i + 1;
    }

    int element;

    cout << "Enter the element to search: ";
    cin >> element;

    int position;

    // Measure Linear Search
    auto begin = high_resolution_clock::now();

    position = linear(data, element);

    auto finish = high_resolution_clock::now();

    cout << "\n----- Linear Search -----" << endl;

    if (position != -1)
        cout << "Element found at index : " << position << endl;
    else
        cout << "Element not found." << endl;

    cout << "Execution Time : "
         << duration_cast<microseconds>(finish - begin).count()
         << " microseconds" << endl;

    // Measure Binary Search
    begin = high_resolution_clock::now();

    position = binary(data, element);

    finish = high_resolution_clock::now();

    cout << "\n----- Binary Search -----" << endl;

    if (position != -1)
        cout << "Element found at index : " << position << endl;
    else
        cout << "Element not found." << endl;

    cout << "Execution Time : "
         << duration_cast<microseconds>(finish - begin).count()
         << " microseconds" << endl;

    return 0;
}
