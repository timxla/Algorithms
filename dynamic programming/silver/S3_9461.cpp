//https://www.acmicpc.net/problem/9461
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N;
    int arr[100];
    arr[0] = 0;
    arr[1] = arr[2] = arr[3] = 1;
    arr[4] = arr[5] = 2;
    arr[6] = 3;
    arr[7] = 4;
    arr[8] = 5;
    arr[9] = 7;
    arr[10] = 9;
    cin >> T;
    for (int i = 11; i <= 100; i++)
    {
        arr[i] = arr[i-1] + arr[i-5];
    }

    for (int i = 0; i < T; i++)
    {
        cin >> N;
        cout << arr[N] << endl;
    }

    return 0;
}
#include <iostream>
#define N_MAX 100
int main() { 
    long long P[N_MAX] = { 0,1, 1, 1, 2, 2, 3, 4, 5, 7, 9 };
    for (long long idx = 11; idx <= N_MAX; idx++)
        P[idx] = P[idx - 1] + P[idx - 5];
    int T;  scanf("%d", &T);
    while (T--){
        int sub; scanf("%d", &sub);
        printf("%lld\n", P[sub]);
    }
    return 0;
}
