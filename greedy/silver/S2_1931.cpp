#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;

int N;

//order in fastest ending time blocks
bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    else return a.second < b.second;
}

int main()
{
    cin >> N;
    vector<pair<ll, ll> > arr(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end(), comp);

    int endpoint = arr[0].second;
    int timeblock = 1;

    for (int i = 1; i < N; ++i)
    {
        if (endpoint <= arr[i].first)
        {
            endpoint = arr[i].second;
            timeblock++;
        }
    }

    cout << timeblock;

    return 0;
}