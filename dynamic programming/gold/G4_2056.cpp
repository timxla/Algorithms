#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 10010
using namespace std;

int N;
int n;
int T[MAX];
int inDegree[MAX];
vector<int> tasks[MAX];
int dp[MAX];

int main()
{
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> T[i] >> n;
        for (int j = 1; j <= n; ++j)
        {
            int tmp;
            cin >> tmp;
            tasks[tmp].push_back(i);
            inDegree[i]++;
        }
    }

    int ans = 0;
    queue<int> q;

    for (int i = 1; i <= N; ++i)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
            dp[i] = T[i];
        }
    }

    while (!q.empty())
    {
        int task = q.front();
        q.pop();

        for (int nx : tasks[task])
        {
            inDegree[nx]--;
            if (inDegree[nx] == 0)
            {
                q.push(nx);
            }           

            dp[nx] = max(dp[nx], dp[task] + T[nx]);
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
}