// Gas station : every city has a gas station ($ per l)
// one l is enough gas to go one km
// calculate least cost that you can spend to go from first city to last

#include <iostream>
#define ll long long

using namespace std;

int N;
ll dist[100000];
ll price[100001];

int main()
{
    // input
    cin >> N;
    for (int i = 0; i < N-1; ++i)
    {
        cin >> dist[i];
    }
    for (int i = 0; i < N; ++i)
    {
        // Doesn't the price of the last station not matter?
        cin >> price[i];
    }

    int pos = 0;
    ll ans = 0;
    ans += price[pos] * dist[pos];

    for (int i = 1; i < N; ++i)
    {
        if (price[i] < price[pos])
        {
            pos = i;
        }
        ans += price[pos] * dist[i];
    }

    cout << ans << endl;

    return 0;
}