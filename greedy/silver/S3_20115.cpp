#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

int N;
double drinks[100001];
double ans = 0;

bool comp(int i, int j)
{
    if (i > j) return true; else return false;
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> drinks[i];
    }

    sort(drinks, drinks+N, comp);
    
    ans += drinks[0];

    for (int i = 1; i < N; ++i)
    {
        ans += drinks[i]/2;
    }    

    cout << ans << endl;
    return 0;
}