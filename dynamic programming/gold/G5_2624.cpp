#include <iostream>

using namespace std;

int T, K;
int value[101];
int cnt[101];
int dp[10001];

int main()
{
    cin >> T >> K;

    for (int i = 0; i < K; ++i)
    {
        cin >> value[i] >> cnt[i];
    }

    // Like a seed, way to make $0 is 1
    // Initially for example if we have 3x $5 coins
    // and we have to make 15 dollars 
    // dp[15] = dp[15 - 5] + dp[15 - 10] + dp[15 - 15] which is 0 + 0 + 1 = 1
    // then we continue with the other coins
    dp[0] = 1;

    for (int i = 0; i < K; ++i)
    {
        int coin_value = value[i];
        int coin_count = cnt[i];
        for (int j = T; j >= 0; --j)
        {
            for (int k = 1; k <= coin_count && j-(coin_value*k) >= 0; ++k)
            { 
                dp[j] += dp[j-(coin_value * k)];
            }
        }
    }

    cout << dp[T] << '\n';
}