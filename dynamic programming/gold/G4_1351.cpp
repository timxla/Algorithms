#include <iostream>
#include <map>
#define ll long long

using namespace std;

ll N, P, Q;
// use maps for faster lookup
map<ll, ll> A; //idx, value

ll solve(ll n)
{
    if (n == 0) return 1;

    ll& ret = A[n];
    if (ret != 0) return ret;

    // recursion
    return ret = solve(n/P) + solve(n/Q);
}

int main()
{
    cin >> N >> P >> Q;

    cout << solve(N) << endl;

    return 0;
}