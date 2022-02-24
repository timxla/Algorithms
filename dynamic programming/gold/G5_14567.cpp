#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int indeg[1001];
vector<int> graph[1001];
queue<int> q;
int result[1001];

int main()
{
    cin >> N >> M;
    
    for (int i = 1; i <= N; ++i)
    {
        indeg[i] = 0;
        result[i] = 1;
    }

    int preq, next;
    for (int i = 1; i <= M; ++i)
    {
        cin >> preq >> next;
        graph[preq].push_back(next);
        indeg[next]++;
    }

    for (int i = 1; i <= N; ++i)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int j = 0; j < graph[curr].size(); ++j)
        {
            int next = graph[curr][j];
            if (--indeg[next] == 0)
            {
                q.push(next);
            }
            result[next] = max(result[next], result[curr] + 1);
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        cout << result[i] << " ";
    }
    return 0;
}