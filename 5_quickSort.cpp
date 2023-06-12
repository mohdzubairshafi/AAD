#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int random(int p, int r)
{
    srand(time(0));
    return p + (rand() % (r - p + 1));
}

int partition(int arr[], int p, int r)
{

    int index = random(p, r);
    swap(arr[index], arr[r]);
    int pivot = arr[r];
    int j = p - 1;
    for (int i = p; i < r; i++)
    {
        if (arr[i] < pivot)
        {
            j++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j + 1], arr[r]);
    return j + 1;
}

void quickSort(int arr[], int p, int r)
{
    if (p < r)
    {
        int pivot = partition(arr, p, r);
        quickSort(arr, p, pivot - 1);
        quickSort(arr, pivot + 1, r);
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
    quickSort(arr, 0, size - 1);
    cout << "Sorted array: \n";
    print(arr, size);
    return 0;
}