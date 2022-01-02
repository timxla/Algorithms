//https://www.acmicpc.net/problem/9184
#include <iostream>
#include <cstring>

using namespace std;

int dp[55][55][55];

int DP(int x, int y, int z)
{
	if (x <= 0 || y <= 0 || z <= 0) return 1;

	int& ret = dp[x][y][z];
	if (ret != -1) return ret;

	if (x > 20 || y > 20 || z > 20) return ret = DP(20, 20, 20);
	if (x < y && y < z) return ret = DP(x, y, z - 1) + DP(x, y - 1, z - 1) - DP(x, y - 1, z);

	return ret = DP(x - 1, y, z) + DP(x - 1, y - 1, z) + DP(x - 1, y, z - 1) - DP(x - 1, y - 1, z - 1);
}

int main()
{
    int a, b, c;
    memset(dp, -1, sizeof(dp));
    while (true)
    {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << DP(a, b, c) << endl;
    }
    return 0;
}
