// 랜선 자르기
#include <iostream>
#define ll long long

using namespace std;

int main()
{
    int N, M;
    ll lines[10001];
    ll maxx = 0;

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> lines[i];
        if (maxx < lines[i]) maxx = lines[i];
    }

    ll low, mid, high;
    low = 1;
    high = maxx;
    ll ans = 0;

    while (low <= high)
    {
        int cnt = 0;
        mid = (low + high)/2;
        for (int i = 0; i < N; ++i)
        {
            cnt += lines[i] / mid;
        }
        if (cnt >= M)
        {
            if (ans < mid)
            {
                ans = mid;
                low = mid + 1;
            }
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << ans << '\n';

    return 0;
}