#include <iostream>

using namespace std;

int n, k;
// 1 <= n <= 50
int dp[300][300][300];

int dfs(int pies, int pp, int least_pie)
{
    int &ret = dp[pies][pp][least_pie];
    if (ret) return ret;

    if (pp == 1 || pies == pp)
    {
        return ret = 1;
    }

    for (int i = least_pie; i*pp <= pies; i++)
    {
        ret += dfs(pies-i, pp-1, i);
    }
    return ret;
}

int main()
{
    cin >> n;
    cin >> k;

    cout << dfs(n, k, 1) << endl;

    return 0;
}