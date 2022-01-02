#include <iostream>
#define endl '\n'
#define ll long long

using namespace std;

int N;
ll ans;
ll dp[31][31] = {0,};

ll dfs(int W, int H)
{
    if (dp[W][H])
    {
        return dp[W][H];
    }
    if (W == 0)
    {
        return 1;
    }
    dp[W][H] = dfs(W-1, H+1);
    if (H > 0)
        dp[W][H] += dfs(W, H-1);

    return dp[W][H];

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(true)
    {
        cin >> N;
        if (N == 0)
            break;
        ans = dfs(N, 0);
        cout << ans << endl; 
    }

    return 0;
}