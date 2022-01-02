//input : 
//7  
//1 6
//6 3
//3 5
//4 1
//2 4
//4 7

//say that root node is 1, and return the parent node of node
//starting from node2 
//ex)
//node2 parent: 4
//node3 parent: 6 ...

#include <iostream>
#include <vector>
using namespace std;

#define CONST_MAX 100000+1

int N;
bool visited[CONST_MAX];
int parent[CONST_MAX];
vector<int> tree[CONST_MAX];

void findParent(int node)
{
    visited[node] = true;
    
    for (int i = 0; i < tree[node].size(); ++i)
    {
        int next = tree[node][i];
        if (!visited[next])
        {
            parent[next] = node;
            findParent(next);
        }
    }
}

int main()
{
    cin >> N;
    
    for (int i = 0; i < N-1; ++i)
    {
        int node1, node2;
        cin >> node1 >> node2;
        
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);

    }

    findParent(1);

    for (int i = 2; i <= N; ++i)
        cout << parent[i] << "\n";

    return 0;
}
