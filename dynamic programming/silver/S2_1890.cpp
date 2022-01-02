#include <iostream>
#include <cstring>

#define endl '\n'
#define ll long long
using namespace std;

int N;
int MAP[101][101];
ll dp[101][101];

ll solve(int x, int y)
{
    // If out of bounds
    if (x >= N || y >= N) return 0;
    if (MAP[x][y] == 0)
    {
        if (x == N - 1 && y == N - 1) return 1;
        else return 0;
    }
    
    ll& ret = dp[x][y];
    if (ret != -1) return ret;

    ret = 0;
    int move = MAP[x][y];

    // move down
    ret += solve(x + move, y);
    // move right
    ret += solve(x, y + move);
    
    return ret;
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> MAP[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << endl;

    return 0;
}