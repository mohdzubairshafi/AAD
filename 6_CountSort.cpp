#include <bits/stdc++.h>
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

void countSort(int a[], int n)
{
    int output[n + 1];
    int max = getMax(a, n);
    int count[max + 1]; // create count array with size [max+1]

    for (int i = 0; i <= max; ++i)
    {
        count[i] = 0; // Initialize count array with all zeros
    }

    for (int i = 0; i < n; i++) // Store the count of each element
    {
        count[a[i]]++;
    }

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1]; // find cumulative frequency

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--; // decrease count for same numbers
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = output[i]; // store the sorted elements into main array
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
    countSort(arr, size);
    cout << "Sorted array: \n";
    print(arr, size);
    return 0;
}