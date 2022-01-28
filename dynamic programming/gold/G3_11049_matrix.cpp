#include <iostream>
#include <algorithm>
using namespace std;
#define INF 999999999

int N;
int matrix[501][2];
int dp[501][501];

int main()
{
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> matrix[i][0] >> matrix[i][1];
    }

    for (int i = 1; i < N; ++i)
    {
        for (int j = 1; i + j <= N; ++j)
        {
            dp[j][i + j] = INF;
            for (int k = j; k <= i + j; k++)
            {
                dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k+1][i + j] + matrix[j][0] * matrix[k][1] * matrix[i + j][1]);
            }
        }
    }

    cout << dp[1][N] << endl;
    return 0;
}