#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// N: number of hours K: how many subjects
int N, K;
int value[100001];
int hrs[100001];
int dp[1001][10001];

int main()
{
    cin >> N >> K;

    for (int i = 1; i <= K; ++i)
    {
        cin >> value[i] >> hrs[i];
    }

    for (int i = 1; i <= K; ++i)
    {
        for (int j = 0; j <= N; ++j)
        {
            if ((j-hrs[i]) >= 0)
            {
                dp[i][j] = max(dp[i-1][j], value[i] + dp[i-1][j-hrs[i]]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[K][N] << endl; 
    return 0;
}