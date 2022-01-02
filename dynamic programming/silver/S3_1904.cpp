//https://www.acmicpc.net/problem/1904

#include <iostream>

using namespace std;

int main()
{
    int N, ans;
    cin >> N;

    int arr[1000001];

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    
    for (int i = 3; i < N+1; i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
        arr[i] = arr[i]%15746;
    }


    cout << arr[N] << endl;

    return 0;
}
