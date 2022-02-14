// 크리보드
// First I thought it was a bfs problem, but turns out it was a bottom-up
// Always remember that a complicated dfs bfs problem can be solved bottom-up
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

int N;
ll dp[101];

ll solve(int n)
{
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    dp[5] = 5;
    dp[6] = 6; // either print A 6 times or select after 3, copy after 4 and paste after 5 to make 6

    for (int i = 7; i <= n; ++i)
    {
        for (int j = 3; j < i; ++j)
    
        {
            dp[i] = max(dp[i], dp[i-j]*(j-1));
        }
    }

    return dp[n];
}

int main()
{
    cin >> N;

    cout << solve(N) << endl;

    return 0;
}