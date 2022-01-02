#include <iostream>
using namespace std;
int N, ans;
int main()
{
    cin >> N;
    if (N == 4 || N == 7)
    {
        cout << -1 << endl;
        return 0;
    }

    int five = N / 5;
    while (true)
    {
        int tmp = N - (five * 5);
        if (tmp % 3 == 0)
        {
            ans = ans + five + (tmp / 3);
            break;
        }
        five--;
    }

    cout << ans << endl;
    return 0;
}