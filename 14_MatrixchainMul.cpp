#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int matrix_chain_mult(int arr[], int size)
{
    int dp[size][size]; // initialize dp array
    int s[size][size];
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            dp[i][j] = 0;
            s[i][j] = 0;
        }
    }
    for (int len = 2; len < size; len++)
    {
        for (int row = 0, col = len; row < size - len; row++, col++)
        {
            dp[row][col] = INT32_MAX;
            for (int k = row + 1; k < col; k++)
            {
                int q = dp[row][k] + dp[k][col] + arr[row] * arr[k] * arr[col];
                if (q < dp[row][col])
                {
                    dp[row][col] = q;
                    s[row][col] = k;
                }
            }
        }
    }

    cout << "\nThe S matrix indicates the recommended parenthesizations of matrices :" << endl;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }

    return dp[0][size - 1];
}

void printAllMatrix(int arr[], int size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        cout << "A" << i + 1 << " : "
             << "[" << arr[i] << "," << arr[i + 1] << "]" << endl;
    }
}

int main()
{

    int arr[] = {2, 3, 4, 1, 3}; // 24
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Given array of Matrix" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Given " << size - 1 << " Matrixes are : " << endl;
    printAllMatrix(arr, size);

    int min_operation = matrix_chain_mult(arr, size);
    cout << "\nMinimum Operation Required to multiply ";
    cout << "Given " << size - 1 << " Matrixes are : ";
    cout << min_operation << endl;

    return 0;
}