// bottom up or top down?
// 조 짜기
#include <iostream>
using namespace std;

int N;
int sc[1001];
int dp[1001];

int main()
{
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> sc[i];
    }

    for (int i = 1; i <= N; ++i)
    {
        int mm = 10001;
        int mx = 0;
        for (int j = i; j > 0; --j)
        {
            if (sc[j] < mm) mm = sc[j];
            if (sc[j] > mx) mx = sc[j];
            int diff = mx - mm;
            dp[i] = max(dp[i], dp[j-1] + diff);
        }
    }

    cout << dp[N] << endl;

    return 0;
}
// if theres 2 5 7 1
// first check 2 -> only one person in group -> total score 0
// then 2, 5 so check whether 0 + 0 (2, 5 are different groups) is bigger or dp[0] + 5-2 = 3
// then 2, 5, 7 so check whether dp[i] (3) is bigger or 2 by itself (0) and 5 7 are a group (2) which is 2 so 3
// so on