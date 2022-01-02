// dp[west][east]
// dp[1][3] = 3 and so on
// dp[2][2] 0 - 0 = dp[1][1] = 1
//          0 - 0
// dp[2][4] => if all but the last of the western pegs are connected to eastern pegs "IN ORDER"
// dp[2][4] = dp[1][3] + dp[1][2] + dp[1][1]
#include <iostream>
#define endl '\n'

using namespace std;

int T, N, M;
int dp[31][31];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int i = 1; i < 31; ++i)
    {
        dp[1][i] = i;
    }

    for (int i = 2; i < 31; ++i)
    {
        for (int j = i; j < 31; ++j)
        {
            for (int k = j - 1; k >= i - 1; --k)
            {
                dp[i][j] += dp[i - 1][k];
            }
        }
    }

    for (int i = 1; i <= T; ++i)
    {
        cin >> N >> M;
        cout << dp[N][M] << endl;
    }

    return 0;
}