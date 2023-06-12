#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    vector<vector<int>> K(n + 1, vector<int>(W + 1));
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]],
                              K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    cout << "\nKnapsack Table: \n";
    for (size_t i = 0; i < n + 1; i++)
    {
        for (size_t j = 0; j < W + 1; j++)
        {
            cout << K[i][j] << " ";
        }
        cout << endl;
    }

    return K[n][W];
}
int main()
{
    int profit[] = {60, 100, 120};
    int weight[] = {1, 2, 3};
    int W = 5;
    int n = sizeof(profit) / sizeof(profit[0]);

    int maxProfit = knapSack(W, weight, profit, n);
    cout << "\nMaximum Profit : " << maxProfit << endl;

    return 0;
}