//https://www.acmicpc.net/problem/1149
#include <iostream>
#define MAX 99999999

using namespace std;

int min(int a, int b)
{
    if (a > b) return b; else return a;
}

int main()
{
    int N, result = MAX;
    int arr[1001][3];
    int dp[1001][3];

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    // this first for loop : when i = 0, it means the route was started at  0
    for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {
			if (i == k) dp[1][k] = arr[1][k];
			else dp[1][k] = MAX;
		}
		for (int k = 2; k <= N; k++) {
			dp[k][0] = arr[k][0] + min(dp[k - 1][1], dp[k - 1][2]);
			dp[k][1] = arr[k][1] + min(dp[k - 1][0], dp[k - 1][2]);
			dp[k][2] = arr[k][2] + min(dp[k - 1][1], dp[k - 1][0]);
		}
        // So at the end if the starting location is the same as the ending location
        // don't take into account a route that ends in the same idx as in the beginning
		for (int k = 0; k < 3; k++) {
			if (i != k) 
				result = min(result, dp[N][k]);			
		}
	}

    cout << result << endl;

    return 0;
}

