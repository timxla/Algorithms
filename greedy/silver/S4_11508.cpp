#include <iostream>
#include <algorithm>
using namespace std;

int N;
int products[100001];

bool comp(int i, int j)
{
    if (i > j) return true; else return false;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> products[i];
    }

    sort(products, products+N, comp);

    long long sum = 0;
    int count = 1;
    for(int i = 0; i < N; ++i)
    {
        if (count%3 != 0)
        {
            sum += products[i];
        }
        count += 1;
    }

    cout << sum << endl;
    return 0;
}