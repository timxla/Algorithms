#include <iostream>
#include <algorithm>
#define endl '\n'
#define ll long long

using namespace std;

int N, ans;
int kids[201]; 
int dp[201];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> kids[i];
    }
    ans = 0;

    fill_n(dp, 201, 1);
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            if (kids[i] > kids[j])
            {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        ans = max(dp[i], ans);
    }

    cout << N - ans << endl;
}