#include <iostream>
using namespace std;

int main()
{
    int Z[41] = {1}, O[41] = {0, 1};
    for (int n = 2; n <41; n++)
    {
        Z[n] = Z[n-1] + Z[n-2];
        O[n] = O[n-1] + O[n-2];
    }

    int N, num;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        cout << Z[num] << ' ' << O[num] << endl;
    }
    return 0;
}
