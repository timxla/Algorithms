//https://www.acmicpc.net/problem/11053
#include <iostream>
#include <algorithm>
#define endl '\n'

using namespace std;

int A, maxstreak = 1;
int arr[1001];
int dp[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A;
    for (int i = 0; i < A; ++i)
    {
        cin >> arr[i];
    }
    fill_n(dp, 1001, 1);

    for (int i = 0; i < A; ++i)
    {
        int entry = arr[i];
        for (int j = 0; j < i; ++j)
        {
            int value = arr[j];
            if (entry < value)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxstreak = max(maxstreak, dp[i]);
    }

    cout << maxstreak << "\n";

    return 0;
}