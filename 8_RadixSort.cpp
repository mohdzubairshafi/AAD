#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int getMax(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

void countingSort(int a[], int n, int place)
{
    int output[n + 1];
    int count[10] = {0};

    // Calculate count of elements
    for (int i = 0; i < n; i++)
        count[(a[i] / place) % 10]++;

    // Calculate cumulative frequency
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(a[i] / place) % 10] - 1] = a[i];
        count[(a[i] / place) % 10]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

void radixsort(int a[], int n)
{
    int max = getMax(a, n);
    for (int place = 1; max / place > 0; place *= 10)
        countingSort(a, n, place);
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
    radixsort(arr, size);
    cout << "Sorted array: \n";
    print(arr, size);
    return 0;
}