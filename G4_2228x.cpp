#include <iostream>
#include <cstring>
#include <algorithm>
#define INT_MIN -1e9

using namespace std;

int N, M;
int arr[101];
// dp[index][prevnum selected or not][number of groups left];
int dp[101][2][55];

int solve(int idx, int status, int remain)
{
    if (idx == N-1)// if this element is the last element in array
    {
        if (remain == 0)
        {
            if (status == 1 && arr[idx] > 0)
            {
                return arr[idx];
            }
            else
                return 0;
        }
        else if (remain == 1 && status == 0)
        {
            return arr[idx];
        }
        else
            return INT_MIN;
    }
    if (remain < 0) return INT_MIN;

    if (dp[idx][status][remain] != INT_MIN) return dp[idx][status][remain];

    int selected = INT_MIN;
    int not_selected = INT_MIN;

    if (status == 0) // prev not selected
    {
        selected = solve(idx+1, 1, remain-1);
        not_selected = solve(idx+1, 0, remain);
    }
    else // status == 1
    {
        selected = solve(idx+1, 1, remain);
        not_selected = solve(idx+1, 0, remain);
    }
    int value; 
    if (selected == INT_MIN or not_selected == INT_MIN)
    {
        if (selected == INT_MIN)
        {
            if (not_selected == INT_MIN)
            {
                value = 0;
            }
            else
            {
                value = not_selected;
            }
        }
        else
        {
            value = selected + arr[idx];
        }
    }
    else
    {
        value = max(selected + arr[idx], not_selected);
    }
    dp[idx][status][remain] = value;
    return value;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < 101; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 55; ++k)
            {
                dp[i][j][k] = INT_MIN;
            }
        }
    }

    cout << solve(0, 0, M) << endl;

    return 0;
}