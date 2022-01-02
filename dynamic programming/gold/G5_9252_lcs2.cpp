#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

#define endl '\n'

using namespace std;

string S, T;
int dp[1001][1001];
string ans[1001][1001];

int main()
{
    cin >> S >> T;
    
    for (int i = 1; i <= S.size(); ++i)
    {
        for (int j = 1; j <= T.size(); ++j)
        {
            if (S[i-1] == T[j-1])
            {
                // 1. Compare S[0] with T[0] ~ T[5]
                // If they are the same, then add one to dp[][]
                dp[i][j] = dp[i-1][j-1] + 1;
                // If they are the same, then add previous history + current char
                ans[i][j] = ans[i][j] + ans[i-1][j-1] + S[i-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if (ans[i - 1][j].length() > ans[i][j - 1].length())
                {
                    ans[i][j] = ans[i - 1][j];
                }
                else
                {
                    ans[i][j] = ans[i][j - 1];
                }
            }
        }
    }

    // for (int i = 0; i <= S.size(); ++i)
    // {
    //     for (int j = 0; j <= T.size(); ++j)
    //     {
    //         cout << "[" << i << "]" << "[" << j << "] = " << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[S.size()][T.size()] << endl << ans[S.size()][T.size()] << endl;
    return 0;
}