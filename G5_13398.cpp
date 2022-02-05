#include <iostream>
#include <algorithm>

using namespace std;

int N, ans;
int arr[100001];
int dp[100001];
int dp2[100001];

int main()
{
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    ans = -999999;
    dp[0] = arr[0];

    for (int i = 1; i < N; ++i)
    {
        dp[i] = max(arr[i], dp[i-1] + arr[i]);
    }

    for (int i = 0; i < N; ++i)
    {
        if(dp[i] > ans)
            ans = dp[i];
    }

    cout << ans << endl;

    return 0;
}