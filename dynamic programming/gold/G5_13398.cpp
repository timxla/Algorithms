// 연속합2
// it was hard because unlike 연속합1 you had to think about two cases
// 1. original 연속합1 value
// 2. value when one element from the array was deleted 
#include <iostream>
#include <algorithm>

using namespace std;

int N, ans;
int arr[100001];
// dp[index][whether or not you deleted an element or not]
int dp[100001][2];

int main()
{
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    dp[0][0] = arr[0];
    dp[0][1] = arr[0];
    ans = arr[0];

    for (int i = 1; i < N; ++i)
    {
        dp[i][0] = max(arr[i], dp[i-1][0] + arr[i]);
        // Important line: if you delete element at i then you're just finding the greatest value until i-1
        // If you already deleted an element beforehand then you have to add current arr[i] to 
        // dp[i-1][1] which is greatest value when there was an element deletion until i-1
        dp[i][1] = max(dp[i-1][0], dp[i-1][1] + arr[i]);
        // compare three values (original ans, dp value at i, dp value at i when there is a deletion)
        ans = max(max(ans, dp[i][0]), dp[i][1]);
    }

    cout << ans << endl;

    return 0;
}