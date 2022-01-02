#include <iostream>
#define endl '\n'
#define MOD 9901
using namespace std;

int N;
int dp[100001][3];

int dfs(int now, int prev)
{
    if (now == N) return 1;
    if (dp[now][prev] != 0) return dp[now][prev];

    if (prev == 0)
    {
        dp[now][prev] += (dfs(now + 1, 0) + dfs(now + 1, 1) + dfs(now + 1, 2)) % MOD;
    }

    else if(prev == 1)
    {
        dp[now][prev] += (dfs(now+1, 0) + dfs(now+1, 2)) % MOD;        
    }
    else if(prev == 2)
    {
        dp[now][prev] += (dfs(now+1, 0) + dfs(now+1, 1)) % MOD;    
    }
    
    return dp[now][prev] % MOD;
}

int main()
{
    cin >> N;

    cout << dfs(0, 0) << endl;

    return 0;
}