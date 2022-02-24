#include <iostream>
#include <cstring>

using namespace std;

int N, C;
double M, P;
int value[5001];
int price[5001];
int dp[10001];

int solve(int budget)
{
    if (dp[budget] != -1) return dp[budget];

    dp[budget] = 0;

    for (int i = 0; i < N; ++i)
    {
        if (budget - price[i] >= 0)
        {
            dp[budget] = max(dp[budget], value[i] + solve(budget - price[i]));
        }
    }

    return dp[budget];
}

int main()
{
    while (true)
    {
        memset(dp, -1, sizeof(dp));
        cin >> N >> M;
        if (N == 0 && M == 0.00) break;

        int budget = (M*100 + 0.5);

        for (int i = 0; i < N; ++i)
        {
            cin >> C >> P;
            value[i] = C;
            price[i] = (P*100 + 0.5);
        }

        cout << solve(budget) << endl;
    }
}