// *** train cars
// dp bottom up (can be solved top down)
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, C;
int train[50010];
// dp[how many small cars][in section 0 ~ idx]
int dp[4][50010];
// sum of cars starting from 0 until idx
int sum[50010];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> train[i];
        sum[i] = sum[i-1] + train[i];
    }
    cin >> C;

    for (int i = 1; i <= 3; ++i)
    {
        for (int j = i * C; j <= N; ++j)
        {
            // max(dont select current car, select current car)
            dp[i][j] = max(dp[i][j-1], dp[i-1][j-C] + (sum[j] - sum[j-C]));
        }
    }

    cout << dp[3][N] << endl;

    return 0;
}