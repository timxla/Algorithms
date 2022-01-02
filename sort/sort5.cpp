#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    int cnt = 0;
    int arr[11];
    cin >> N;

    while (N > 0)
    {
        arr[cnt] = N%10;
        N /= 10;
        cnt++;
    }
    sort(arr, arr+cnt);

    for (int i = 0; i < cnt; ++i)
    {
        cout << arr[cnt-i-1];
    }
    return 0;
}
