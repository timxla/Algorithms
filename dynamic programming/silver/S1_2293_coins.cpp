#include <iostream>

using namespace std;

int n, k;
int cointype[101];
int dp[10001];

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> cointype[i];
    }

    dp[0] = 1; // Only one way to make no coins; Dont choose any
    for (int i = 0; i < n; ++i) // for every cointype
    {
        for (int j = cointype[i]; j <= k; ++j) // for every "total coin value"
        {
            dp[j] += dp[j - cointype[i]];
        }
    }

    cout << dp[k] << endl;
    
    return 0;
}