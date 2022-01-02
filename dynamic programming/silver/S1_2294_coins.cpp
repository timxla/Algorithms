// Coins 2
// dp
#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX 100001

using namespace std;

int N, K;
int coins[101];
// dp[i] = The least number of coins needed to make i
int dp[100001];

int main()
{
    cin >> N >> K;
    for (int i = 0; i <= K; ++i)
    {
        dp[i] = 100001;
    }

    for (int i = 1; i <= N; ++i)
    {
        cin >> coins[i];
        // If K == 12 and there is a cointype 12 then you only need one coin
        dp[coins[i]] = 1;
    }

    // 
    for (int i = 1; i <= N; ++i)
    {
        // for every cointype :
        for (int j = coins[i]; j <= K; ++j)
        {
            // There is a smaller way to make K if dp[i - cointype] + 1 < dp[i]
            // Ex) if the cointype is 12 and we're making 14
            // 14 - 12 = 2, 2 + 1 = 3. If current dp[i] was 4, then utilizing cointype
            // 12 with dp[2] will be the optimal solution.
            // (this example might not be possible in the problem just an explanation)
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }

    // There is no solution
    if (dp[K] == 100001)
    {
        cout << -1 << endl;
    }
    else 
    {
        cout << dp[K] << endl;
    }
    return 0;
}