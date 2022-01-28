// dp increasing digits
#include <iostream>
#include <cstring>
#define ll long long

using namespace std;

int T;
int arr[1001];
// dp[i][j] means value when there are i digits and j is the last digit
// so dp[4][2] -> xxx2
ll dp[65][10];

// dp[i][j] = dp[i-1][0] + dp[i-1][1] + .. + dp[i-1][9]


int main()
{
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < 10; ++i)
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i < 65; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            for (int k = 0; k <= j; ++k)
            {
                dp[i][j] += dp[i-1][k];
            }
        }
    }

    for (int i = 0; i < T; ++i)
    {
        int num = arr[i];
        ll ans = 0;
        for (int j = 0; j < 10; ++j)
        {
            ans += dp[num][j];
        }
        cout << ans << endl;
    }
    
    return 0;
}