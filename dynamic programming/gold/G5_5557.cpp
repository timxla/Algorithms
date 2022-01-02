// 1학년
// dp
#include <iostream>
#include <cstring>
#include <vector>
#define endl '\n'
#define ll long long

using namespace std;

int N, result;
int num[105];
// dp[index][total (if total is over 20 or less than 0 you dont need to store it)]
ll dp[105][21];

ll dfs(int idx, int total)
{
    if (total > 20 || total < 0) return 0;
    
    if (idx == N - 1)
    {
        if (total == result) return 1;
        else return 0;
    }

    ll& ret = dp[idx][total];
    if (ret != -1) return ret;

    ret = 0;
    ret = ret + dfs(idx + 1, total + num[idx]) + dfs(idx + 1, total - num[idx]);
    return ret;

}

int main()
{
    cin >> N;
    for (int i = 0; i < N-1; ++i)
    {
        cin >> num[i];
    }
    cin >> result;

    memset(dp, -1, sizeof(dp));

    cout << dfs(1, num[0]) << endl;

    return 0;
}