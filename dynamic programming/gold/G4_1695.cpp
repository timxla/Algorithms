#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 5005
using namespace std;

int N;
int arr[MAX];
int dp[MAX][MAX];

int solve(int left, int right)
{
    if (left >= right) return 0;

    int& ret = dp[left][right];
    if (ret != -1) return ret;

    ret = 0;
    if (arr[left] == arr[right])
    {
        ret += solve(left+1, right-1);
    }
    else
    {
        ret += min(solve(left+1, right), solve(left, right-1)) + 1;
    }
    return ret;
}

int main()
{
    cin >> N;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    cout << solve(0, N-1) << endl;
    return 0;
}