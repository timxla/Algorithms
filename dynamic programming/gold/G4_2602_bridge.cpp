#include <iostream>
#include <algorithm>
#include <string>
#define endl '\n'

using namespace std;

//angelbridge = 1, demonbridge = 0
int dp[2][101][21];
int bridgelength;
string scroll;
string angel;
string demon;

// (bridge type, bridge index, scroll index)
int nextPath(int bridge, int bi, int si)
{
    // current scroll index matches scroll size
    if (si == scroll.size()){
        return 1;
    } 

    int &result = dp[bridge][bi][si];
    if (result != -1) return result;

    result = 0;
    if (bridge == 0) // if bridge is demonbridge
    {
        for (int i = bi; i <= bridgelength; ++i)
        {
            if (scroll[si] == demon[i])
            {
                result += nextPath(1, i+1, si+1);
            }
        }
    }
    else
    {
        for (int i = bi; i <= bridgelength; ++i)
        {
            if (scroll[si] == angel[i])
            {
                result += nextPath(0, i+1, si+1);
            }
        }
    }
    dp[bridge][bi][si] = result;
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> scroll;
    cin >> demon;
    cin >> angel;
    bridgelength = demon.size();

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 101; ++j)
        {
            for (int k = 0; k < 21; ++k)
            {
                dp[i][j][k] = -1;
            }
        }
    } 
    cout << nextPath(0, 0, 0) + nextPath(1, 0, 0) << endl;
    return 0;
}