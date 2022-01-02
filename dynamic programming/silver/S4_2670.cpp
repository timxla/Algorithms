// Longest continuous product

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int N;
	double dp[10000], num[10000], maxval = -1;

    cin >> N;

	for(int i=0; i<N; i++){

        cin >> num[i];
		if(i == 0)
			dp[i] = num[i];
		else{
			dp[i] = max(num[i], dp[i-1]*num[i]);
		}
		maxval = max(maxval, dp[i]);
	}

    // num = [1.1, 0.9, 1.3, 0.9, 1.4, ....]
    // dp = [1.1, max(0.9, 1.1*0.9) = 0.99, max(1.3, 0.99*1.3) = 1.3, ....]
    cout << fixed;
    cout.precision(3);
    cout << maxval;
}
