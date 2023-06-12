#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int getMax(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}
void bucketsort(int a[], int n)
{
    int max = getMax(a, n);
    int bucket[max], i;
    for (int i = 0; i <= max; i++)
    {
        bucket[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        bucket[a[i]]++;
    }
    for (int i = 0, j = 0; i <= max; i++)
    {
        while (bucket[i] > 0)
        {
            a[j++] = i;
            bucket[i]--;
        }
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
    bucketsort(arr, size);
    cout << "Sorted array: \n";
    print(arr, size);
    return 0;
}
