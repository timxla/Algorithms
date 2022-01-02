// 구간 합 구하기
#include <iostream>
#define MAX 1025

using namespace std;

// N is the matrix dimension, M is number of answers we need to find
// 0 <= N <= 1024, 0 <= M <= 100000
int N, M, num;

int grid[MAX][MAX];
int sum_grid[MAX][MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> num;

            sum_grid[i + 1][j + 1] = sum_grid[i + 1][j] + sum_grid[i][j + 1] - sum_grid[i][j] + num;
        }
    }

    for (int i = 0; i < M; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << sum_grid[x2][y2] - sum_grid[x1 - 1][y2] - sum_grid[x2][y1 - 1] + sum_grid[x1 - 1][y1 - 1] << "\n";

    }
    return 0;
}