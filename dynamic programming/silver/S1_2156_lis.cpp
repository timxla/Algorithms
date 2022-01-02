//https://www.acmicpc.net/problem/2156
#include <iostream>
#define endl '\n'
#define MAX 10001

using namespace std;
int N;
int arr[MAX];
int dp[MAX];

int max(int a, int b)
{
    if (a > b) return a; else return b;
}

int main(void)
{
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> arr[i]; 
    }
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    
    for (int i = 3; i <= N; ++i)
    {
        dp[i] = max(max(dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i]), dp[i-1]);
    }
    cout << dp[N] << endl;

    return 0;
}
