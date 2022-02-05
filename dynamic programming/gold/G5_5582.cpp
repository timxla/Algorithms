// 공통 부분 문자열
// different from lcs in that the letters have to be consecutive, unlike lcs
#include <iostream>
#include <string>
#include <algorithm>
#define endl '\n'

using namespace std;

string S, T;
// dp[S_starting point][T_starting point]
int dp[4001][4001] = {0};

int main()
{
    cin >> S;
    cin >> T;

    int s_len = S.size();
    int t_len = T.size();

    for (int i = 1; i <= s_len; ++i)
    {
        for (int j = 1; j <= t_len; ++j)
        {
            if (S[i-1] == T[j-1])
            {
                if (S[i] == T[j])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i-1][j-1]++;
                }
            }
        }
    }

    int max = 0;

    for (int i = 0; i < s_len; ++i)
    {
        for (int j = 0; j < t_len; ++j)
        {
            if (dp[i][j] > max)
            {
                max = dp[i][j];
            }
        }
    }

    cout << max << endl;
    
    return 0;
}