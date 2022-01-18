#include <iostream>
#include <algorithm>

using namespace std;

int N, ans;
int ropes[100001];

bool myfunction (int i, int j) { return (i>j); }

int main()
{
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> ropes[i];
    }

    sort(ropes, ropes+N, myfunction);

    for (int i = 0; i < N; ++i)
    {
        int value = ropes[i] * (i+1);
        if (value > ans)
        {
            ans = value;
        }
    }

    cout << ans << endl;
    
    return 0;
}
