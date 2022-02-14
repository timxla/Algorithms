#include <iostream>
#include <vector>
using namespace std;

int N, R, Q;
vector<int> graph[100001];
bool visited[100001] = {false};
int queries[100001];
int child_num[100001];

int solve(int node)
{
    if (child_num[node] != 0) return child_num[node];

    vector<int> conn = graph[node];
    int len = conn.size();
    visited[node] = true;
    int ret = 1; // Original value is 1 becuase root is already visited

    for (int i = 0; i < len; ++i)
    {
        if (visited[conn[i]] == true) continue;
        ret += solve(conn[i]);
    }

    child_num[node] = ret;
    return ret;
}

int main()
{
    cin >> N >> R >> Q;

    for (int i = 1; i < N; ++i)
    {
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    for (int i = 0; i < Q; ++i)
    {
        cin >> queries[i];
    }

    int xx = solve(R);

    for (int i = 0; i < Q; ++i)
    {
        cout << child_num[queries[i]] << '\n';
    }

    return 0;
}