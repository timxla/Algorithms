#include <iostream>
#include <cstring>
using namespace std;

int T, n, k;
int dp[101][100][2];

int main()
{
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        cin >> n >> k;
        memset(dp, 0, sizeof(dp));
        
        // length 1 and no ones next to each other - only 2ways 0, 1
        dp[1][0][0] = dp[1][0][1] = 1;

        for (int j = 0; j <= k; ++j)
        {
            for (int i = 2; i <= n; ++i)
            { 
                dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
                dp[i][j][1] = dp[i-1][j][0] + dp[i-1][j-1][1];
            }
        }

        cout << dp[n][k][0] + dp[n][k][1] << '\n';
    }
}