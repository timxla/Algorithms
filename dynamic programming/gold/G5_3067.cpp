// knapsack problem
// how many ways to make target number?
#include <iostream>
#include <cstring>
using namespace std;

int T, N, M;
int coins[21];
int dp[10001];

int main()
{
    cin >> T;

    while (T--)
    {
        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            cin >> coins[i];
        }
        cin >> M;

        memset(dp, 0, sizeof(dp));

        dp[0] = 1;
        for (int i = 0; i < N; ++i)
        {
            for (int j = coins[i]; j <= M; ++j)
            {
                dp[j] += dp[j-coins[i]];
                // this means if coins[i] = 5 then from values 0~4 if you add coin 5 then you get 5~9
                // so dp[5~9] += dp[0~4]
            }
        }

        cout << dp[M] << '\n';

    }
    return 0;
}