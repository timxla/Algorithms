#include <iostream>

using namespace std;

int L, P, V;
int cnt;
int main()
{
    cnt = 0;
    while (true)
    {
        cin >> L >> P >> V;
        if (L + P + V == 0)
        {
            break;
        }
        cnt++;
        int blocknum = V / P;
        int rem = V % P;
        int finalrem;
        if (rem >= L)
        {
            finalrem = L;
        }
        else{
            finalrem = rem;
        }
        int ans = (blocknum * L) + finalrem;
        cout << "Case " << cnt << ": " << ans << endl;
    }
    return 0;
}