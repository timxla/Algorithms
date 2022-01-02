// I dont understand

#include <iostream>
#include <cstring>

#define endl '\n'
#define ll long long
#define MAX 201

using namespace std;

int N, K;
ll dp[MAX][MAX];

int dfs(int n, int k)
{
    if (n == 1)
    {
        dp[n][k] = k;
    }    
    else if (k == 1)
    {
        dp[n][k] = 1; 
    }
    else if (dp[n][k] == 0)
    {
        dp[n][k] = dfs(n - 1, k) + dfs(n, k - 1);
    }
    return dp[n][k] % 1000000000;
}

int main()
{
    cin >> N >> K;

    memset(dp, 0, sizeof(dp));
    cout << dfs(N, K) << endl;

    return 0;
}