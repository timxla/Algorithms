#include <iostream>
#include <cmath>
#include <cstring>

#define endl '\n'

using namespace std;

int N;
int dp[100005];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {   
        dp[i] = i; // There is a way to use only 1s to form the number  4 = 1^2 + 1^2 + 1^2 + 1^2
        for (int j = 1; j * j <= i; ++j)
        {
            // For example, if dp[43] == 36 + 4 + 1 + 1 + 1 == 5, but dp[43 - 25] + 1 = dp[18] + 1 = 3
            // dp[43] (5) > dp[18] + 1 (3) update!
            if (dp[i] > dp[i - j*j] + 1)
            {
                dp[i] = dp[i - j*j] + 1;
            }
        }
    }
    cout << dp[N] << endl;
    return 0;
}