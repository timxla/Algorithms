#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

int N; 
ll M[10001];
ll ans;

int main()
{
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> M[i];
    }

    sort(M, M+N);

    if (N % 2 != 0)
    {
        ans = M[N-1]; 
        N--;
    }

    for (int i = 0; i < N/2; ++i)
    {
        ll val = (M[i] + M[N-1-i]);
        if (val > ans) ans = val;
    }

    cout << ans << endl;

    return 0;
}