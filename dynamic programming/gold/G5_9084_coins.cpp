#include <iostream>
#include <cstring>
#define endl '\n'

using namespace std;

int T, N, target;
int coins[21];
int dp[10001];

int main()
{
    cin >> T;

    for (int i = 1; i <= T; ++i)
    {
        cin >> N;
        for (int j = 1; j <= N; ++j)
        {
            cin >> coins[j];
        }
        cin >> target;

        memset(dp, 0, sizeof(dp));
        // Only one way to make no coins : select none!
        dp[0] = 1;

        for (int j = 1; j <= N; ++j)
        {
            for (int k = coins[j]; k <= target; ++k)
            {
                dp[k] += dp[k - coins[j]];
            }
        }

        cout << dp[target] << endl;
    }
    return 0;
}