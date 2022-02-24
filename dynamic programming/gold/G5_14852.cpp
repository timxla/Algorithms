#include <iostream>
#define ll long long
#define mmm 1000000007

using namespace std;

int N;
ll dp[1000001][2];

int main()
{
    cin >> N;
    dp[0][0] = 0;
    dp[1][0] = 2;
    dp[2][0] = 7;
    dp[2][1] = 1;
    for (int i = 3; i < N+1; ++i)
    {
        dp[i][1] = (dp[i-1][1] + dp[i-3][0]) % mmm;
        dp[i][0] = (3*dp[i-2][0] + 2*dp[i-1][0] + 2*dp[i][1]) % mmm;
    }

    cout << dp[N][0] << endl;

    return 0;
}