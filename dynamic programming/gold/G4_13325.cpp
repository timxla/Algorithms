#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const int MAX = 1 << 21;
int N;
int edges[MAX];
int nodeNum = 0;
int ans = 0;

int dfs(int idx)
{
    if (idx * 2 >= nodeNum)
    {
        ans += edges[idx];
        return edges[idx];
    }

    else
    {
        int leftNode = dfs(idx*2);
        int rightNode = dfs(idx*2 +1);
        ans += edges[idx] + abs(leftNode - rightNode);
        return edges[idx] + max(leftNode, rightNode);
    }
}

int main()
{
    cin >> N;

    // x << y == x times 2^y
    // x >> y == x divided by 2^y
    nodeNum = 1 << (N+1);
    // i starts at 2 why? because the topmost node is node number 1
    // so because edge values are given save the values at index of child node number

    //                             P(1)
    // this value stored at idx 2 / \ this value stored at idx 3
    //                          C(2) C(3)
    for (int i = 2; i < nodeNum; ++i)
    {
        cin >> edges[i];
    }

    dfs(1);

    cout << ans << endl;    

    return 0;
}