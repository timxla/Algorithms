#include <iostream>
#define MAX 9999999999

using namespace std;

int N, M;
bool Xday[101] = {false};
int dp[101][101];

int dfs(int day, int coupon)
{
    if (day > N) return dp[day][coupon];
    if (dp[day][coupon] != MAX) return dp[day][coupon];
    if (Xday[day] == true)
    {
        dp[day][coupon] = min(dp[day][coupon], dfs(day+1, coupon));
        return dp[day][coupon];
    }

    dp[day][coupon] = min(dp[day][coupon], dfs(day+1, coupon) + 10000);
    dp[day][coupon] = min(dp[day][coupon], dfs(day+1, coupon+1) + 25000);
    dp[day][coupon] = min(dp[day][coupon], dfs(day+1, coupon+2) + 37000);

    if (coupon >= 3)
    {
        dp[day][coupon] = min(dp[day][coupon], dfs(day+1, coupon-3));
    }
    
    return dp[day][coupon];
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < M; ++i)
    {
        int a;
        cin >> a;
        Xday[a] = true;
    }

    fill_n(dp, sizeof(dp), MAX);

    int ans = dfs(1, 0);    
    
    cout << ans << endl;
    return 0;
}