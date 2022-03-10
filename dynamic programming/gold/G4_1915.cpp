// biggest square of 1s
// The point is setting dp[x][y] -> the biggest square that you can make with its right-bottommost corner at x,y
// you can compare the top, left-top diagonal, and left dp elements, because the biggest square will be the minimum of the three
// if they are all one number, for example 2, then dp[x][y] will be three (draw it!)
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int N, M;
    char num;
    int arr[1001][1001];
    int dp[1001][1001];

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> num;
            int A = num - '0';
            arr[i][j] = A;    
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
    cout << ans * ans << '\n';
    return 0;
}