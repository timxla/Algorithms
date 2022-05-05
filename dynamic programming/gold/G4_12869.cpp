#include <iostream>
#include <algorithm>

using namespace std;
int N;
int scv[3] = {0, };
bool visited[100][61][61][61] = {false, };
int ans = 100000;
int hp[6][3] = {{1, 3, 9}, {1, 9, 3}, {9, 1, 3}, {9, 3, 1}, {3, 1, 9}, {3, 9, 1}};

void solve(int x, int a, int b, int c)
{
    if (a <= 0 && b <= 0 && c <= 0)
    {
        ans = min(ans, x);
        return;
    }

    for (int i = 0; i < 6; ++i)
    {
        if (!visited[x+1][a-hp[i][0]][b-hp[i][1]][c-hp[i][2]])
        {
            visited[x+1][a-hp[i][0]][b-hp[i][1]][c-hp[i][2]] = true;
            solve(x+1, a-hp[i][0], b-hp[i][1], c-hp[i][2]);
        }
    }
    return;
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> scv[i];
    }

    solve(0, scv[0], scv[1], scv[2]);

    cout << ans << endl;
    return 0;
}