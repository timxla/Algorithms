#include <iostream>
#define MOD 100000

using namespace std;

int W, H;
int dp[101][101][4];

int main()
{
    cin >> W >> H;

    for (int i = 1; i <= H; ++i)
    {
        dp[i][1][0] = 1;
    }

    for (int j = 1; j <= W; ++j)
    {
        dp[1][j][2] = 1;
    }

    for (int i = 2; i <= H; ++i)
    {
        for (int j = 2; j <= W; ++j)
        {
            dp[i][j][0] = (dp[i-1][j][1] + dp[i-1][j][0]) % MOD;
            dp[i][j][1] = dp[i-1][j][2];
            dp[i][j][2] = (dp[i][j-1][3] + dp[i][j-1][2]) % MOD;
            dp[i][j][3] = dp[i][j-1][0];
        }
    }

    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                cout << dp[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    int ans = 0;
    for (int i = 0; i < 4; ++i)
    {
        ans += dp[H][W][i];
    }

    cout << ans % MOD << endl;

    return 0;
}