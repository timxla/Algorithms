#include <iostream>
#include <algorithm>

#define endl '\n'
using namespace std;

int N, K;
int dp[100001];

int main()
{
    cin >> N >> K;
    for (int i = 1; i < K; ++i)
    {
        for (int j = 1; j < K; ++j)
        {
            dp[1] = i;
            dp[2] = j;
            for (int k = 3; k <= N; ++k)
            {
                dp[k] = dp[k-1] + dp[k-2];
            }
            if (dp[N] == K)
            {
                cout << i << endl;
                cout << j << endl;
                return 0;
            }
        }
    }
    return 0;
}