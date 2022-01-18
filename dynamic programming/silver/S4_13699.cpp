#include <iostream>
#define ll long long

using namespace std;

int x;
ll dp[40], temp;

int main()
{
    cin >> x;
    
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= x; ++i)
    {
        temp = 0;
        for (int j = 0; j < i; ++j)
        {
            temp += dp[j] * dp[i-j-1];
        }
        dp[i] = temp;
    }

    cout << dp[x] << endl;

    return 0;
}