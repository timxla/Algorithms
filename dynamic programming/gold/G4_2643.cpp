#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

struct paper{
    int w;
    int h;
};

int N;
vector<paper> arr;
int dp[1010];

bool comp(paper a, paper b)
{
    if (a.h > b.h) return true;
    else if (a.h == b.h) return a.w > b.w;
    return false;
}

int main()
{
    cin >> N;

    int a, b;
    for (int i = 0; i < N; ++i)
    {
        cin >> a >> b;
        paper tmp;
        if (a < b)
        {
            tmp.w = a;
            tmp.h = b;
        }
        else
        {
            tmp.w = b;
            tmp.h = a;
        }
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end(), comp);

    for (int i = 0; i < N; ++i)
    {
        dp[i] = 1;
    }
    
    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if ((arr[i].w <= arr[j].w) && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}