#include <iostream>
#include <cstring>

#define endl '\n'
using namespace std;

int N, K;
int dp[1005][1005];

int biCo(int N, int K)
{
    if (K == 0 || K == N)
    {
        return 1;
    }    
    
    if (dp[N][K] != -1) return dp[N][K];

    dp[N][K] = biCo(N - 1, K - 1) + biCo(N - 1, K);
    return dp[N][K] % 10007;
}

int main()
{
    cin >> N >> K;

    memset(dp, -1, sizeof(dp));

    int ans = biCo(N, K);
    cout << ans << endl;
    return 0;
}
