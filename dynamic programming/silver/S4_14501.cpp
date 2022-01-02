#include <iostream>
#include <algorithm>
#define endl '\n'

using namespace std;

int N, ans;
int T[16];
int P[16];
int dp[16];


int main()
{
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> T[i] >> P[i];
    }

    for (int i = N; i >= 1; --i)
    {
        if ((i + T[i]) > (N + 1)) dp[i] = dp[i + 1];
        else dp[i] = max(dp[i + 1], dp[i + T[i]] + P[i]);
    }

    cout << dp[1] << endl;
}