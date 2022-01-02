#include <iostream>
#include <algorithm>
#include <vector>

#define endl '\n'
using namespace std;

int n, ans;
int arr[100001];
int dp[100001]; 

int main()
{
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    ans = -999999;
    dp[0] = arr[0];
    for (int i = 1; i < n; ++i)
    {
        dp[i] = max(arr[i], dp[i-1] + arr[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        if(dp[i] > ans)
            ans = dp[i];
    }

    cout << ans << endl;

    return 0;
}