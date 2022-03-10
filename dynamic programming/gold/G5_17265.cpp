#include <iostream>
#include <algorithm>
using namespace std;

int N;
int mn = 100000; int mx = -100000;
char graph[5][5];
int visited[5][5];

void dfs(int x, int y, int num)
{
    if (x == N-1 && y == N-1)
    {
        if (num < mn) mn = num;
        if (num > mx) mx = num;
        return;
    }
    for (int i = 0; i < 2; ++i)
    {
        int X = x+i;
        int Y = y-i+1;
        if (x >= N || y >= N) continue;
        if (!visited[x][y])
        {
            visited[x][y] = 1;
            int next_num = graph[X][Y] - '0';
            if (graph[x][y] == '+') dfs(X, Y, num + next_num);
            else if (graph[x][y] == '-') dfs(X, Y, num - next_num);
            else if (graph[x][y] == '*') dfs(X, Y, num * next_num);
            // else its a number
            else dfs(X, Y, num);
            // important point you have to reset visited to 0 because when the for loop ends
            // that means that one route is completed, so you have to reset visited to 0 to look for other routes
            visited[x][y] = 0;
        }
    }
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> graph[i][j];
        }
    }

    dfs(0, 0, graph[0][0] - '0');

    cout << mx << ' ' << mn << '\n';

    return 0;
}