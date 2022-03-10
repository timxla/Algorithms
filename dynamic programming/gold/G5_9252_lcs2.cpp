#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

#define endl '\n'

using namespace std;

string S, T;
int dp[1001][1001];
stack<char> stk;

int main()
{
    cin >> S >> T;
    int ss = S.size();
    int ts = T.size();

    for (int i = 1; i <= ss; ++i)
    {
        for (int j = 1; j <= ts; ++j)
        {
            if (S[i-1] == T[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }


    while (dp[ss][ts] != 0)
    {
        if (dp[ss][ts] == dp[ss][ts-1])
        {
            ts--;
        }
        else if (dp[ss][ts] == dp[ss-1][ts])
        {
            ss--;
        }
        else if (dp[ss][ts] == dp[ss-1][ts-1] + 1)
        {
            stk.push(S[ss-1]);
            ss--;
            ts--;
        }
    }

    cout << dp[S.size()][T.size()] << endl;    
    while (!stk.empty())
    {
        cout << stk.top();
        stk.pop();
    }

    return 0;
}