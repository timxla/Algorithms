// 나무 자르기
#include <iostream>
#define ll long long
#define MAX 1000000 + 1

using namespace std;

ll N, M;
ll trees[MAX];
ll maxx = 0;


int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> trees[i];
        if (maxx < trees[i]) maxx = trees[i];
    }

    ll low, mid, high;

    low = 0;
    high = maxx;
    ll h = 0;

    while (low <= high)
    {
        ll cnt = 0;
        mid = (low + high)/2;

        for (int i = 0; i < N; ++i)
        {
            if (trees[i] >= mid)
            {
                cnt += trees[i] - mid;
            }
        }
        if (cnt == M)
        {
            h = mid;
            break;
        }
        else if (cnt > M)
        {
            if (h < mid) h = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << h << endl;
    
    return 0;
}