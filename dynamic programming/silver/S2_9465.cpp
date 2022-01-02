#include <iostream>
#include <algorithm>
#define endl '\n'

using namespace std;

int T, n, ans;
int l1[100001], l2[100001];
int dp[100001][2];

void solve()
{
    for (int i = 1; i <= n; ++i)
    {
        cin >> l1[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        cin >> l2[i];
    }
    dp[1][0] = l1[1];
    dp[1][1] = l2[1];

    dp[2][0] = dp[1][1] + l1[2];
    dp[2][1] = dp[1][0] + l2[2];    
    for (int i = 3; i <= n; ++i)
    {
        dp[i][0] = max(dp[i-1][1], dp[i-2][1]) + l1[i];
        dp[i][1] = max(dp[i-1][0], dp[i-2][0]) + l2[i];
    }

    ans = max(dp[n][0], dp[n][1]);

    // for (int i = 0; i <= n; ++i)
    // {
    //     for (int j = 0; j <= 1; ++j)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << ans << endl;
}

int main()
{
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        cin >> n;
        solve();
    }
    return 0;
}