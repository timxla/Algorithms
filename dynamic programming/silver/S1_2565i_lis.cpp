// electric line problem
#include <iostream>
#include <algorithm>
#include <cstdlib>
#define endl '\n'

using namespace std;

struct Line
{
    int left;
    int right;
};

int N, ans;
int dp[101];
Line pole[101];

bool compare(Line &a, Line &b)
{
    if (a.left < b.left) return true;
    else return false;
}

int main()
{
    cin >> N;
    ans = 0;

    for (int i = 1; i <= N; ++i)
    {
        cin >> pole[i].left >> pole[i].right;
    }

    fill_n(dp, 101, 1);
    sort(pole + 1, pole + N + 1, compare);
    
    for (int i = 1; i <= N; ++i)
    {
        for (int j = i; j >= 1; --j)
        {
            if (pole[i].right > pole[j].right)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << N - ans << endl;

    return 0;
}


