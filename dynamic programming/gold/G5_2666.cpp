#include <iostream>
#include <algorithm>
#include <cstring>

#define endl '\n'
#define MAX 20 + 1

using namespace std;

// N = Number of cabinets
// M = Number of cabients that we need to open in order
// a = Initially open cabinet 1 b = Initially open cabinet 2
int N, M, a, b;
int order[MAX];
// dp[Open cabinet 1][Open cabinet 2][index]
int dp[MAX][MAX][MAX];

int solve(int a, int b, int orderidx)
{
    if (orderidx > M) return 0;

    int &ret = dp[a][b][orderidx];
    if (ret != -1)
                return ret;

    // distance from open door 1 to door of current orderidx + move all doors and solve()
    // vs distance from open door 2 to door of current orderidx + move all doors and solve()
    ret = min(
        // moved open door a to order[orderidx]
        abs(order[orderidx] - a) + solve(order[orderidx], b, orderidx + 1), 
        // moved open door b to order[orderidx]
        abs(order[orderidx] - b) + solve(a, order[orderidx], orderidx + 1));

    return ret;

}

int main()
{
    cin >> N;
    cin >> a >> b;
    cin >> M;
    for (int i = 1; i <= M; ++i)
    {
        cin >> order[i];
    }
    
    memset(dp, -1, sizeof(dp));

    cout << solve(a, b, 1) << endl;

    return 0;
}