#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Bubble Sort
void bubble(vector<int> &a)
{
    int size = a.size();

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

// Selection Sort
void selection(vector<int> &a)
{
    int size = a.size();

    for (int i = 0; i < size - 1; i++)
    {
        int smallest = i;

        for (int j = i + 1; j < size; j++)
        {
            if (a[j] < a[smallest])
                smallest = j;
        }

        swap(a[i], a[smallest]);
    }
}

// Insertion Sort
void insertion(vector<int> &a)
{
    int size = a.size();

    for (int i = 1; i < size; i++)
    {
        int current = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > current)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = current;
    }
}

// Merge Function
void mergeArray(vector<int> &a, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> first(n1), second(n2);

    for (int i = 0; i < n1; i++)
        first[i] = a[left + i];

    for (int j = 0; j < n2; j++)
        second[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (first[i] <= second[j])
            a[k++] = first[i++];
        else
            a[k++] = second[j++];
    }

    while (i < n1)
        a[k++] = first[i++];

    while (j < n2)
        a[k++] = second[j++];
}

// Merge Sort
void mergeSorting(vector<int> &a, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSorting(a, left, mid);
        mergeSorting(a, mid + 1, right);

        mergeArray(a, left, mid, right);
    }
}

// Partition Function
int divide(vector<int> &a, int low, int high)
{
    int pivot = a[high];
    int index = low - 1;

    for (int i = low; i < high; i++)
    {
        if (a[i] < pivot)
        {
            index++;
            swap(a[index], a[i]);
        }
    }

    swap(a[index + 1], a[high]);

    return index + 1;
}

// Quick Sort
void quickSorting(vector<int> &a, int low, int high)
{
    if (low < high)
    {
        int p = divide(a, low, high);

        quickSorting(a, low, p - 1);
        quickSorting(a, p + 1, high);
    }
}

// Function to create random array
void createArray(vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        a[i] = rand() % 1000;
    }
}

int main()
{
    const int SIZE = 100;

    vector<int> original(SIZE);
    vector<int> copyArray;

    srand(time(NULL));

    createArray(original);

    cout << "Array Size : " << SIZE << endl << endl;

    auto start = high_resolution_clock::now();
    copyArray = original;
    bubble(copyArray);
    auto end = high_resolution_clock::now();
    cout << "Bubble Sort      : "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;

    start = high_resolution_clock::now();
    copyArray = original;
    selection(copyArray);
    end = high_resolution_clock::now();
    cout << "Selection Sort   : "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;

    start = high_resolution_clock::now();
    copyArray = original;
    insertion(copyArray);
    end = high_resolution_clock::now();
    cout << "Insertion Sort   : "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;

    start = high_resolution_clock::now();
    copyArray = original;
    mergeSorting(copyArray, 0, SIZE - 1);
    end = high_resolution_clock::now();
    cout << "Merge Sort       : "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;

    start = high_resolution_clock::now();
    copyArray = original;
    quickSorting(copyArray, 0, SIZE - 1);
    end = high_resolution_clock::now();
    cout << "Quick Sort       : "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds" << endl;

    return 0;
}
