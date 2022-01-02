#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000001
using namespace std;

// int N;
// int dp[MAX];
// vector<int> hist;

// int dfs(int num)
// {
//     if (num <= 1) return 0;
//     if (dp[num] != MAX) return dp[num];
    
//     if (num % 3 == 0)
//     {
//         dp[num] = min(dfs(num/3), dfs(num-1)) + 1;
//         return dp[num];
//     }

//     if (num % 2 == 0)
//     {
//         dp[num] = min(dfs(num/2), dfs(num-1)) + 1;
//         return dp[num];
//     }

//     else
//     {
//         dp[num] = dfs(num-1) + 1;
//         return dp[num];
//     }
// }


// int main()
// {
//     cin >> N;
    
//     dp[0] = -1;
//     dp[1] = 0;
//     for (int i = 2; i <= N; ++i)
//     {
//         dp[i] = MAX;
//     }

//     cout << dfs(N) << endl;

//     while (N != 0)
//     {
//         cout << N << " ";
//         if (dp[N] == dp[N - 1] + 1)
//         {
//             N = N - 1;
//         }
//         else if (N % 2 == 0 && dp[N] == dp[N / 2] + 1)
//         {
//             N = N / 2;
//         }
//         else if (N % 3 == 0 && dp[N] == dp[N / 3] + 1)
//         {
//             N = N / 3;
//         }
//     }

//     return 0;
// }

int dp[1000001];
int before[1000001];

int solve(int x) {
	dp[1] = 0;
	before[1] = -1;

	for (int i = 2; i <= x; ++i) {
		dp[i] = dp[i - 1] + 1;
		before[i] = i - 1;

		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
			dp[i] = dp[i / 2] + 1;
			before[i] = i / 2;
		}
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
			dp[i] = dp[i / 3] + 1;
			before[i] = i / 3;
		}
	}

	return dp[x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	cout << solve(n) << '\n';
	
	while (n != -1) {
		cout << n << ' ';
		n = before[n];
	}
	cout << '\n';

	return 0;
}