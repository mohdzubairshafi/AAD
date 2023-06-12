#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void merge(int arr[], int p, int q, int r)
{
    int n = q - p + 1;
    int m = r - q;
    int temp1[n + 1];
    int temp2[m + 1];
    for (int i = 0; i < n; i++)
    {
        temp1[i] = arr[p + i];
    }
    for (int i = 0; i < m; i++)
    {
        temp2[i] = arr[q + i + 1];
    }
    temp1[n] = INT32_MAX;
    temp2[m] = INT32_MAX;

    int j = 0;
    int k = 0;
    for (int i = p; i <= r; i++)
    {
        if (temp1[j] < temp2[k])
        {
            arr[i] = temp1[j++];
        }
        else
        {
            arr[i] = temp2[k++];
        }
    }
}

void mergeSort(int arr[], int p, int r)
{

    if (p < r)
    {
        int q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
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
    int arr[] = {1, 3, 4, 4, 4, 6, 76, 1, 46, 7, 8, 4, 2, 2, 5, 8, 22};
    int size = sizeof(arr) / sizeof(int);
    cout << "UnSorted array: \n";
    print(arr, size);
    mergeSort(arr, 0, size - 1);
    cout << "Sorted array: \n";
    print(arr, size);
    return 0;
}