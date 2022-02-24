#include <iostream>
#include <string>

using namespace std;

string num;
int dp[41];


int main()
{
    cin >> num;
    int len = num.size();
    dp[0] = 1;
    for (int i = 0; i < len; ++i)
    {
        int curr = num[i] - '0';
        int next = num[i+1] - '0';
        if (curr != 0)
        {
            dp[i+1] += dp[i];
            if (curr * 10 + next <= 34)
                dp[i+2] += dp[i];
        }
    }

    cout << dp[len] << endl;
    return 0;
}