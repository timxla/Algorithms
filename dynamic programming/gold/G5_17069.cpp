#include <iostream>
#include <algorithm>
#include <cstring>
#define endl '\n'
#define MAX 36
#define ll long long

using namespace std;

int N;
ll answer;
int MAP[MAX][MAX];
// dp[x][y][position]
ll dp[MAX][MAX][3];

int a[] = {0, 1, 1};
int b[] = {1, 1, 0};

// function check()
// According to the current position, check if the next move, whatever move it may be,
// doesn't run into any walls
bool check(int row, int col, int pos)
{
    if (pos == 0)
    {
        if (MAP[row][col+1] == 1) return false;
    }

    else if (pos == 1)
    {
        if (MAP[row][col+1] == 1 || MAP[row+1][col] == 1 || MAP[row+1][col+1] == 1) return false;
    }

    else if (pos == 2)
    {
        if (MAP[row+1][col] == 1) return false;
    }
    return true;
}

ll solved(int row, int col, int pos)
{
    ll value = 0;

    if (row == N && col == N)
    {
        return 1;
    }

    // There is no path
    else if (row > N || col > N) return 0;

    ll &ret = dp[row][col][pos];
    if (ret != -1)
    {
        return ret;
    }

    // If current position is horizontal
    if (pos == 0)
    {
        for (int k = 0; k < 2; ++k)
        {
            if (check(row, col, k))
            {
                value += solved(row + a[k], col + b[k], k);
            }
        }
    }

    // If current position is diagonal
    else if (pos == 1)
    {
        for (int k = 0; k < 3; ++k)
        {
            if (check(row, col, k))
            {
                value += solved(row + a[k], col + b[k], k);
            }
        }
    }

    // If current position is vertical
    else // (pos = 2)
    {
        for (int k = 1; k < 3; ++k)
        {
            if (check(row, col, k))
            {
                value += solved(row + a[k], col + b[k], k);
            }
        }
    }
    ret = value;
    return ret;
}

int main()
{
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> MAP[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    answer = solved(1, 2, 0);
    cout << answer << endl;
    
    return 0;
}
