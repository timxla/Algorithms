#include <iostream>
#include <vector>
#define endl '\n'
#define ll long long

using namespace std;

int N, K;
int weight[101], value[101];
int dp[101][100001];

int max(int a, int b)
{
    return (a > b) ? a : b;
}
 
// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    vector<vector<int> > K(n + 1, vector<int>(W + 1));
 
    // Build table K[][] in bottom up manner
    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                                K[i - 1][w - wt[i - 1]],
                                K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}
 
// Driver Code
int main()
{
    cin >> N >> K;
    int val[101];
    int wt[101];

    for (int i = 0; i < N; ++i)
    {
        cin >> wt[i] >> val[i];
    }
    cout << knapSack(K, wt, val, N) << endl;
     
    return 0;
}