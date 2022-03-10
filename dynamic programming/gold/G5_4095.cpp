#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    while (true)
    {
        int N, M;
        int arr[1001][1001];
        int dp[1001][1001];

        cin >> N >> M;
        if (N == 0 && M == 0) break;

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < 1001; ++i)
        {
            for (int j = 0; j < 1001; ++j)
            {
                dp[i][j] = 0;
            }
        }
 
        int ans = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (arr[i][j] == 1)
                {
                    dp[i][j] = 1;
                    if (i > 0 && j > 0)
                    {
                        dp[i][j] += min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                    }
                }
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}