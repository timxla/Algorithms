#include <iostream>
#include <vector>

#define max(A,B) (((A)>(B))?(A):(B)) 
#define endl '\n'
using namespace std;

int N, ans = 0;
int forest[501][501];
// dp[x][y] = Number of valid moves left on this location
int dp[501][501];

// Use during for loop to  express movement
int xmove[4] = {1, -1, 0, 0};
int ymove[4] = {0, 0, 1, -1};

int eat(int x, int y)
{
    int &ret = dp[x][y];
    if (ret != 0) return ret;

    ret = 1;

    for (int i = 0; i < 4; ++i)
    {
        int nx = x + xmove[i];
        int ny = y + ymove[i];

        // If next move is not out of bounds
        if (nx <= N && ny <= N && nx >= 1 && ny >= 1)
        {
            // If next patch of forest has more food
            if (forest[nx][ny] > forest[x][y])
            {
                // compare current dp value and dp value if we chose next patch
                // dp value at next location + one move to move from x,y to next location
                ret = max(ret, eat(nx, ny) + 1);
            }
        }
    }
    return ret;
}

int main()
{
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> forest[i][j];
        }
    }


    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            ans = max(ans, eat(i, j));
        }
    }

    cout << ans << endl;
    
    return 0;
}