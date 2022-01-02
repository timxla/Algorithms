//https://www.acmicpc.net/problem/1932
#include <iostream>
#define endl '\n'
#define MAX 501

using namespace std;

int main()
{
    int N, ans;
    int dp[MAX][MAX];
    int arr[MAX][MAX];

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            cin >> arr[i][j];
        }
    }
    arr[0][0] = arr[0][1] = arr[1][0] = dp[0][0] = dp[0][1] = dp[1][0] = 0;
    dp[1][1] = arr[1][1];

    for (int i = 2; i <= N; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            if (dp[i-1][j-1]  < dp[i-1][j])
            {
                dp[i][j] = dp[i-1][j] + arr[i][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j-1] + arr[i][j];
            }
        }
    }
    ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (ans < dp[N][i])
        {
            ans = dp[N][i];
        }
    }

    cout << ans << endl;

    return 0;
}
