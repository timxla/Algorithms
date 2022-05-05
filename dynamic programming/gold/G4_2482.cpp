#include <iostream>
#include <cstring>
#define MOD 1000000003

using namespace std;

int N;
int K;
// Important point: dp[choose][#]
// where choose means the number of slots that are chooseable
// and # means number of slots that you have to choose
int dp[1001][1001];

int solve(int x, int pick)
{
    if (x == 0 || pick * 2 > x) return 0;
    if (pick == 1) return x;

    int &ret = dp[x][pick];
    if (ret != -1) return ret;

    // choose - 1 -> skipped adjacent slot and chose the next one, so 2 slots are not chooseable anymore(x-2)
    // choose -> you didnt choose the next available slot, so just subtract 1 from chooseable slots
    return ret = (solve(x-2, pick-1) + solve(x-1, pick)) % MOD;
}

int main()
{
    cin >> N >> K;
    memset(dp, -1, sizeof(dp));
    cout << solve(N, K) << endl;

    return 0;
}