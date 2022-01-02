#include <iostream>
#define endl '\n'

using namespace std;

int N, M, ans, marker;
int vip[41];
int dp[41];

int main()
{
    vip[0] = 0;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    cin >> N;
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        cin >> vip[i];
    }

    // Initialize dp
    for (int i = 3; i <= 40; ++i)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    ans = 1;
    marker = 0;
    for (int i = 0; i < M; ++i)
    {
        int end = vip[i];
        ans *= dp[end - marker - 1];
        marker = end; 
    }
    ans *= dp[N - marker];

    cout << ans << endl;
    return 0;
    
}
