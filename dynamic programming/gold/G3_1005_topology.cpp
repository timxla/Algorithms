#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int T, W; // Test case, end node
int N, K; // Number of buildings, Number of edges 
int X, Y; // X -> Y

int TIME[1001]; // Time it takes to build building i (TIME[i])
int inDegree[1001]; // Indegree
int result[1001];

int main()
{
    cin >> T;
    for (int tc = 0; tc < T; ++tc)
    {
        memset(TIME, 0, sizeof(TIME));
        memset(inDegree, 0, sizeof(inDegree));
        memset(result, 0, sizeof(result));
        vector<int> graph[1001]; // Graph

        cin >> N >> K;

        for (int i = 1; i <= N; ++i)
        {
            cin >> TIME[i];
            result[i] += TIME[i];
        }

        for (int i = 0; i < K; ++i)
        {
            cin >> X >> Y;
            graph[X].push_back(Y);
            ++inDegree[Y];            
        } 
        cin >> W;

        queue<int> q;
        for (int i = 1; i <= N; ++i)
        {
            if (inDegree[i] == 0)
            {
                q.push(i); // Push beginning nodes
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int to_node : graph[node])
            {
                result[to_node] = max(result[to_node], result[node] + TIME[to_node]);
                if (--inDegree[to_node] == 0)
                {
                    q.push(to_node);
                }
            }
        }
        cout << result[W] << endl;
    }
    return 0;
}
