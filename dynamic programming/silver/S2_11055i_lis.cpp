#include <iostream>

using namespace std;

int N, maxvalue;
int A[1001];
int dp[1001];

int max(int a, int b)
{
    if (a > b) return a; return b;
}

int main()
{
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }

    maxvalue = 0;    
    fill_n(dp, 1001, 0);

    for (int i = 1; i <= N; ++i)
    {
        dp[i] = A[i];
        for (int j = 1; j < i; ++j)
        {
            if (A[i] > A[j])
            {
                dp[i] = max(dp[i], dp[j] + A[i]);
            }
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        if (dp[i] > maxvalue) maxvalue = dp[i];
    }
    cout << maxvalue << endl;

}