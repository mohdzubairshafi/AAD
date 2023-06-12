#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int size, int index)
{
    int largest = index;
    int left = index * 2;
    int right = index * 2 + 1;
    if (left < size && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        heapify(arr, size, largest);
    }
}
void heapSort(int arr[], int size)
{
    for (int i = size / 2; i >= 0; i--)
    {
        heapify(arr, size, i);
    }
    for (int i = size - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void print(int arr[], int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 3, 4, 4, 4, 6, 2, 5, 8, 9, 22};
    int size = sizeof(arr) / sizeof(int);
    cout << "UnSorted array: \n";
    print(arr, size);
    heapSort(arr, size);
    cout << "Sorted array: \n";
    print(arr, size);
    return 0;
}