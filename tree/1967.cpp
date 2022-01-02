#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// Stores <child, weight> maybe arr index is node number?
vector <pair<int, int> > arr[10001];

// If node is visited, true
bool visit[10001] = {false, };

// Total distance
int dist = 0;

//?
int endNode;

void dfs(int start, int cost)
{
    if (visit[start] == true)
        return;
    visit[start] = true;

    if (dist < cost)
    {
        dist = cost;
        endNode = start;
    }

    for (int i = 0; i < arr[start].size(); ++i)
    {
        dfs(arr[start][i].first, cost + arr[start][i].second);
    }
}

int main()
{
    // Stores 12 (number of nodes)
    int N;
    cin >> N;
    
    for (int i = 0; i < N-1; ++i) // For 0-10 so 11 times
    {
        int parent, child, weight;
        cin >> parent >> child >> weight;
        arr[parent].push_back(make_pair(child, weight));
        arr[child].push_back(make_pair(parent, weight)); 
    }
    dfs(1, 0);
    dist = 0;
    memset(visit, false, sizeof(visit));
    dfs(endNode, 0);

    cout << dist << endl;

    return 0;
}
