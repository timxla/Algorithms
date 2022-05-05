#include <iostream>
#include <vector>
#include <cstring> 

using namespace std;

int N, M;
vector<int> hierarchy[100001];
int score[100001];

void dfs(int id)
{
    for (int i = 0; i < hierarchy[id].size(); ++i)
    {
        int next = hierarchy[id][i];
        score[next] += score[id];
        dfs(next);
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        int tmp;
        cin >> tmp;
        if (tmp == -1)
            continue;
        hierarchy[tmp].push_back(i);
    }

    for (int i = 1; i <= M; ++i)
    {
        int workerID, S;
        cin >> workerID >> S;
        score[workerID] += S;
    }

    dfs(1);

    for (int i = 1; i <= N; ++i)
    {
        cout << score[i] << ' ';
    }
    
    return 0;
}


