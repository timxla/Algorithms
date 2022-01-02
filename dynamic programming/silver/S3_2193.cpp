#include <iostream>
#define endl '\n'
#define ll long long
using namespace std;

int n;
ll dp[91];

int main()
{
    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i < 91; ++i)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n] << endl;
    return 0;
}