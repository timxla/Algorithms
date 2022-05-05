#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int height[5005];
vector<int> trails[5005];
int cnt = 0;
int ans = 0;

void dfs(int point)
{
    for (int i = 0; i < trails[point].size(); ++i)
    {
        bool nomore = true;
        if (height[point] < height[trails[point][i]])
        {
            nomore = false;
            cnt++;
            dfs(trails[point][i]);
        }
        if (nomore && i == trails[point].size()-1)
        {
            cnt = 0;
            if (ans < cnt) ans = cnt;
            return;
        }
    }
    return;
}

int main()
{
    cin >> N >> M;
    int min = 1000001;
    int index = 0;
    for (int i = 1; i <= N; ++i)
    {
        cin >> height[i];
        if (height[i] < min)
        {
            min = height[i];
            index = i;
        } 
    }

    int x, y;
    for (int i = 1; i <= M; ++i)
    {
        cin >> x >> y;
        trails[x].push_back(y);
        trails[y].push_back(x);
    }

    for (int i = 1; i <= N; ++i)
    {
        dfs(i);
        cout << cnt << endl;
        ans = 0;
        cnt = 0;
    }
    return 0;
}