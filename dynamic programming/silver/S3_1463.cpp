//https://www.acmicpc.net/problem/2579
#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

int min(int a, int b)
{
    if (a < b) return a; else return b;
}

int main() 
{
	int N;
	cin >> N;
	vector<int> dp(N + 1);

	//bottom-up
	dp[1] = 0;
	for (int i = 2; i <= N; i++) 
    {
		dp[i] = dp[i - 1] + 1;
		if (!(i % 3)) dp[i] = min(dp[i],dp[i / 3] + 1);
		if (!(i % 2)) dp[i] = min(dp[i], dp[i / 2] + 1);
	}

	cout << dp[N] << endl;

	return 0;
}
