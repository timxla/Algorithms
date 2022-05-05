#include <iostream>
#include <cstring>

using namespace std;

int N;
int dp[1001][2][3];

int solve(int idx, int late, int abst)
{
    if (idx == N) return 1;

    int& ret = dp[idx][late][abst];
    if (ret != -1) return ret;

    int value = 0;
    // O
    value += solve(idx+1, late, 0) % 1000000;
    // L
    if (late+1 < 2)
    {
        value += solve(idx+1, late+1, 0) % 1000000;
    }
    // A
    if (abst+1 < 3)
    {
        value += solve(idx+1, late, abst+1) % 1000000;
    }

    ret = value % 1000000;
    return ret;
}

int main()
{
    cin >> N;
    memset(dp, -1, sizeof(dp));

    cout << solve(0, 0, 0) << endl;

    return 0;
}