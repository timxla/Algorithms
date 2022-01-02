#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int N; 
vector<int> dp;

int main() {

	cin >> N; 
    dp.push_back(1);
    dp.push_back(3);

    for (int i = 2; i < N; i++){
        dp.push_back((dp[i - 1] + 2*dp[i - 2])%10007);
	}
    cout << dp[N - 1];
	
    return 0;
}