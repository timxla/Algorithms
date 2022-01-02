#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

int M, N;
int MAP[501][501];
int dp[501][501];

int movex[4] = {1, 0, -1, 0};
int movey[4] = {0, 1, 0, -1};

bool checkInbound(int x, int y)
{
    if (x < M && y < N && x >= 0 && y >= 0) return true;
    else return false;
}

int dfs(int x, int y)
{
    // If x, y == M-1, N-1: Path is found
    if (x == M - 1 && y == N - 1) return 1;

    int& ret = dp[x][y];
    if (ret != -1) return ret;
    
    ret = 0;
    
    // x + 1, y or x, y + 1 or x - 1, y or x, y - 1
    // (down, right, up, left)
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + movex[i];
        int ny = y + movey[i];

        if (checkInbound(nx, ny))
        {
            if (MAP[nx][ny] < MAP[x][y])
            {
                ret += dfs(nx, ny);
            }
        }
    }
    return ret;
}

int main()
{
    cin >> M >> N;
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> MAP[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << dfs(0, 0) << endl;

    return 0;
}