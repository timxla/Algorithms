#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int start_vol;
int max_vol;
int volume[101];
int dp[101];

int dfs(int vol, int nextsong)
{
    cout << vol << " " << nextsong << endl;
    if (nextsong == N + 1)
    {
        if (vol > max_vol || vol < 0)
        {
            return -1;
        }
        else
        {
            return vol;
        }
    }

    int &ret = dp[nextsong];
    if (ret != -1) return ret;
    
    ret = max(dfs(vol + volume[nextsong], nextsong + 1), dfs(vol - volume[nextsong], nextsong + 1));
    return ret;
}

int main()
{
    cin >> N >> start_vol >> max_vol;

    for (int i = 1; i <= N; ++i)
    {
        cin >> volume[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << dfs(start_vol, 1) << endl;
    return 0;
}