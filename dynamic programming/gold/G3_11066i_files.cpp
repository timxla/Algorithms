// dp
// 파일 합치기, 여러가지 풀이법 복습 

#include <iostream>
#include <cstring>

#define endl '\n'
#define M 501
using namespace std;

// dp[i][j] = Minimum cost for adding files from i to j
int dp[M][M];
int files[M];
int sum[M];
int T, N;

int dfs(int ix, int jx)
{
    if (dp[ix][jx] != 0x3f3f3f3f)
        return dp[ix][jx];

    if (ix == jx)
    { 
        dp[ix][jx] = 0;
        return 0;
    }

    if (ix + 1 == jx)
    {
        dp[ix][jx] = files[ix] + files[jx];
        return dp[ix][jx];
    }

    // [a, b, c, d, e, f g] if ix = b and jx = e, then from b to e dfs
    // 1. b | c d e -> mid == b
    // 2. b c | d e -> mid == c
    for (int mid = ix; mid < jx; ++mid)
    {
        int left = dfs(ix, mid);
        int right = dfs(mid + 1, jx);
        if (dp[ix][jx] > left + right)
        {
            dp[ix][jx] = left + right;
        }
    }

    // test case 4
    //           40 30 30 50
    // if jx == 4 and ix == 2
    // sum[jx] = sum from ix to jx so 150
    // sum[ix - 1] = 40
    // so 150 - 40 == 110 which is ((30 + 30) = 60 + 50) = 110
    return dp[ix][jx] += sum[jx] - sum[ix - 1];
}

int main()
{
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        memset(dp, 0x3f, sizeof(dp));
        cin >> N;
        {
            for (int i = 1; i <= N; ++i)
            {
                cin >> files[i];
                // Sum[] is used to calculate the cost needed for finding total sum within selected idx
                sum[i] = sum[i - 1] + files[i];
            }
            cout << dfs(1, N) << endl;
        }
    }
    return 0;
}