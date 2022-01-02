#include <iostream>
#define endl '\n'

using namespace std;


int T, W, ans = -1;
int arr[1001];
int dp[1001][31][3];

void recurse(int index, int movesleft, int pos, int plum)
{
    if (arr[index] == pos) plum++;    
    if (index == T-1)
    {
        if (ans < plum) ans = plum;
        return;
    }
    if (dp[index][movesleft][pos] == -1) dp[index][movesleft][pos] = plum;
    else if (dp[index][movesleft][pos] < plum) dp[index][movesleft][pos] = plum;
    else return;

    recurse(index+1, movesleft, pos, plum);
    if (movesleft > 0 && arr[index+1] != arr[index])
    {
        pos = pos == 1? 2 : 1;
        recurse(index+1, movesleft-1, pos, plum);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T >> W;
    for (int i = 0; i < T; ++i)
    {
        cin >> arr[i];
    }    

    // fill up dp array
    for (int i = 0; i < 1001; ++i)
    {
        for (int j = 0; j < 31; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                dp[i][j][k] = -1;
            }
        }
    }
    recurse(0, W, 1, 0);
    recurse(0, W-1, 2, 0);

    cout << ans << endl;

    return 0;
}