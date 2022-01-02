// Matrix Multiplication
#include <iostream>

#define endl '\n'

using namespace std;

int N;
int A[501][2];
// dp[]
int dp[501][501];

int main()
{
    cin >> N;

    for (int i = 1; i < N; ++i)
    {
        cin >> A[i][0] >> A[i][1];
    }

    for (int i = 1; i < N; ++i)
    {
        for (int j = 1; j < N; ++j)
        {
            dp[i][j] = 0;
        }
    }

    return 0;
}