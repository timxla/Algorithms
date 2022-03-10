#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[1011];
int dp[1011];
vector<int> hist[1011];
vector<int> ans;

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N; ++i)
    {
        // because itself is lis
        dp[i] = 1;
        hist[i].push_back(arr[i]);
        for (int j = 0; j < i; ++j)
        {
            if (arr[i] > arr[j])
            {
                if (dp[i] < dp[j] + 1)
                {
                    hist[i].clear();
                    hist[i] = hist[j];
                    hist[i].push_back(arr[i]);
                    dp[i] = dp[j] + 1;
                }
            }
        }
        if (ans.size() < hist[i].size())
        {
            ans = hist[i];
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}