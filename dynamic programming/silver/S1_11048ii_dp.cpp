#include <iostream>

using namespace std;

int N, M;
int arr[1001][1001];
int dp[1001][1001];

int max(int a, int b, int c)
{
	return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

int dfs(int n, int m)
{
    // If out of bounds
    if (n > N || m > M ) return 0;

    // If we are at the last room
    if (n == N && m == M) return arr[n][m];

    int &ret = dp[n][m];
    if (ret != -1) return ret;    

    // Branch out
    return ret = max(dfs(n + 1, m + 1), dfs(n + 1, m), dfs(n, m + 1)) + arr[n][m];
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> arr[i][j];
        }
    }
    
    for (int i = 0; i <= N; ++i)
    {
        for (int j = 0; j <= M; ++j)
        {
            dp[i][j] = -1;
        }
    }

    cout << dfs(0, 0) << endl;
    return 0;
}