#include <iostream>
#include <algorithm>
#define endl "\n"

using namespace std;

int N, ans;
int arr[1001];
int dp[1001]; 
int rdp[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    arr[0] = dp[0] = rdp[0] =  0;
    for (int i = 1; i <= N; ++i)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; ++i)
    {
        dp[i] = rdp[i] = 1;
    }

    for (int i = 1; i <= N; ++i) 
    {
        for (int j = 1; j <= i; ++j)
        {
            if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    for (int i = N; i > 0; --i)
    {
        for (int j = N; j >= i; --j)
        {
            if (arr[i] > arr[j]) rdp[i] = max(rdp[i], rdp[j] + 1);
        }
    }
    ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (ans < dp[i] + rdp[i] - 1) ans = dp[i] + rdp[i] - 1;
    }
    
    cout << ans << endl;
    
    return 0;
}