#include <iostream>
#include <algorithm>

using namespace std;

int N;
int tip[100001];

bool comp(int i, int j)
{
    if (i > j) return true; else return false;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> tip[i];
    }

    sort(tip, tip+N, comp);
    
    long long sum = 0;
    for (int i = 0; i < N; ++i)
    {
        if ((tip[i] - i) > 0)
        {
            sum += tip[i] - i;
        }
    }

    cout << sum << endl;
    return 0;
}