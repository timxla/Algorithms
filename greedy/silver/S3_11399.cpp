#include <iostream>
#include <algorithm>

using namespace std;

int N;
int P[1001];
int result;

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> P[i];
    }
    sort(P, P+N);
    
    for (int i = 0; i < N; ++i)
    {
        for (int j = i; j >= 0; --j)
        {
            result += P[j];
        }
    }

    cout << result << endl;
    return 0;
}