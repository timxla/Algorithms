#include <iostream>
#include <vector>
using namespace std;

int N, T;
int tm[101];
int score[101];
int dp[101][100001];

int max(int a, int b)
{
    return (a > b) ? a : b;
}

// time, score = weight, value

int solve(int n, int t, int *time, int *score)
{
    int i, w;
    vector<vector<int> > K(n + 1, vector<int>(t + 1));
    for (i = 0; i <= n; ++i)
    {
        for (w = 0; w <= t; ++w)
        {
            if (i == 0 || w == 0)
            {
                K[i][w] = 0;
            }
            else if (time[i-1] <= w)
            {
                K[i][w] = max(score[i-1] + K[i-1][w-time[i-1]], K[i-1][w]);
            }
            else
            {
                K[i][w] = K[i-1][w];
            }
        }
    }
    return K[n][t];
}

int main()
{
    cin >> N >> T;
    for (int i = 0; i < N; ++i)
    {
        cin >> tm[i] >> score[i];
    }
    cout << solve(N, T, tm, score) << endl;
    return 0;
}