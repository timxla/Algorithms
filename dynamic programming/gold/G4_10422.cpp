#include <iostream>
#define MOD 1000000007
#define ll long long
using namespace std;

int T;
int N;
ll dp[5001];

int main()
{
    cin >> T;
    dp[0] = 1;
    dp[2] = 1;

    for (int i = 3; i <= 5000; ++i)
    {
        for (int j = 2; j <= i; ++j)
        {
            dp[i] += dp[j - 2] * dp[i - j];
            dp[i] %= MOD;
        }
    }

    while (T--)
    {
        cin >> N;
        cout << dp[N] << '\n';
    }
    return 0;
}
