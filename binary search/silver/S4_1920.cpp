#include <iostream>
#include <algorithm>

#define endl '\n'

using namespace std;


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    int arr[100001];
    int search[100001];
    int low, mid, high;

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        cin >> search[i];
    }

    sort(arr, arr+N);

    for (int i = 0; i < M; ++i)
    {
        int num = search[i];
        bool found = 0;
        low = 0;
        high = N-1;
        while (low <= high)
        {
            mid = (high + low) / 2;
            if (arr[mid] == num)
            {
                found = 1;
                break;
            }
            else if (arr[mid] < num)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        if (found)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}