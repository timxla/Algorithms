#include <iostream>
#define MOD 1000000007
#define ll long long

using namespace std;

int N;
ll dp[1516][3];
// the three columns are [0]: numbers with remainder 0
// [1]: numbers with remainder 5, [2]: numbers with remainder 10

int main()
{   
    cin >> N;

    dp[1][0] = 0; dp[1][1] = 1; dp[1][2] = 0;
    for (int i = 2; i <= 1515; ++i)
    {
        dp[i][0] = dp[i-1][1] + dp[i-1][2];
        dp[i][1] = dp[i-1][0] + dp[i-1][2];
        dp[i][2] = dp[i-1][0] + dp[i-1][1]; 
        for (int j = 0; j < 3; ++j)
        {
            dp[i][j] = dp[i][j] % MOD;
        }
    }

    cout << dp[N][0] << '\n';
    
    return 0;
}

/*
15 55 -> 1

55%15  remainder 10

so basically if you wanna add 1 or 5 to the front
if you wanna add 1 then the original number % has to be 5
if you wanna add 5 then the original number % has to be 10

15 -> original mod == 0 so no solutions
55 -> original mod == 10 so if you add 5 then there is a solution

115(x)   515(x)  155(x)  555(o) -> 1
mod 10   mod 5   mod 5   mod 0

either add 5 to #1, or add 1 to #2 and #3 so 3 ways for 4 digit combinations
*/