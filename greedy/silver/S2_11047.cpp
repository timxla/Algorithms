#include <iostream>
using namespace std;

int N, K;
int coins[10];
int num;

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        cin >> coins[i];
    }

    for (int i = N-1; i >= 0; --i)
    {
        while (N > 0)
        {
            if (coins[i] <= K)
            {
                K -= coins[i];
                num++;
            }
            else
            {
                break;
            }
        }
    }

    cout << num << endl;
    return 0;
}