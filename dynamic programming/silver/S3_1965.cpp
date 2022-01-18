// lis box version

#include <iostream>
#include <algorithm>

using namespace std;

int n, ans = 0;
int arr[1001];
int dp[1001];


int main()
{
    cin >> n;

    fill_n(dp, 1001, 1);

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }


    for (int i = 1; i < n; ++i)
    {
        int entry = arr[i];
        for (int j = 0; j < i; ++j)
        {
            int value = arr[j];
            if (entry > value)
            {
                dp[i] = max(dp[j]+1, dp[i]);
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
}