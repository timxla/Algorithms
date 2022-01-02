#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

int N;
int cards[1001];
int dp[1001];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> cards[i];
    }

    // for minimum value fill dp with cards
    // if you have to buy N cards then initialize dp with
    // the price of card pack N (Pn)
    for (int i = 1; i <= N; ++i)
    {
        dp[i] = cards[i];
    }
    
    dp[0] = cards[0] = 0;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            // Example:
            // dp[3] = Compare original dp[3] with each case:
            // 1. min value for picking 2 cards (dp[2]) + one-card pack value
            // 2. min value for picking one card + two-card pack value
            // 3. min value for picking a three-card pack
            // minimum value is the answer
            dp[i] = min(dp[i], dp[i-j] + cards[j]);
        }
    }

    cout << dp[N] << endl;
    return 0;
}