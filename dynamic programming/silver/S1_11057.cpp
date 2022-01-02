#include <iostream> 
#include <cstring>
#define endl '\n'
using namespace std;

const int MOD = 10007;


int N;
// dp[Index][Number at current Index]
int dp[1001][11];

int dfs(int index, int number) {
    if (index == N) return 1; 

    int& ret = dp[index][number];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = number; i < 10; ++i) 
        // If N == 2
        // dfs(0, 0) -> dfs(1, 0) -> dfs(2, 0) -> returns 1
        // Means "When number at index 1 is 0 && number at index 2 is 0 N == 00 (so add 1)"
        // then ++i, so dfs(1, 0) -> dfs(2, 1) -> returns 1
        // so value 10 gets returned to dfs(1, 0)
        // Means "When number at index 1 is 0 there are 10 numbers" -> dp[1][0] == 10
    	ret = (ret + dfs(index + 1, i)) % MOD;
    return ret % MOD;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    memset(dp, -1, sizeof(dp));

    cout << dfs(0, 0) << endl;
    return 0;
}