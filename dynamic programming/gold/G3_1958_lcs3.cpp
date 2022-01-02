#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

#define endl '\n'

using namespace std;

string R, S, T;
int dp[101][101][101];

int main()
{
    cin >> R >> S >> T;
    int r = R.size();
    int s = S.size();
    int t = T.size();

    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j <= s; ++j)
        {
            for (int k = 1; k <= t; ++k)
            {
                if (R[i-1] == S[j-1] && S[j-1] == T[k-1])
                {
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                }
                else
                {
                    dp[i][j][k] = max(max(dp[i-1][j][k], dp[i][j-1][k]), dp[i][j][k-1]);
                }
            }
        }
    }
    cout << dp[r][s][t] << endl;
    return 0;
}