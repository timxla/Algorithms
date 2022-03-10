#include <iostream>
#include <cmath>

using namespace std;

int N;

int main()
{
    while (true)
    {
        cin >> N;
        if (N == 0) break;

        int ans = 0;
        int rt = sqrt(N);
        for (int i = 1; i <= rt; ++i)
        {
            if (i*i == N)
            {
                ans++; 
                // dont break out of the last loop
                continue;
            }
            for (int j = i; j <= rt; ++j)
            {
                if (i*i + j*j == N) 
                {
                    ans++;
                    break;
                }
                for (int k = j; k <= rt; ++k)
                {
                    if (i*i + j*j + k*k == N) 
                    {
                        ans++;
                        break;
                    }
                    for (int l = k; l <= rt; ++l)
                    {
                        if (i*i + j*j + k*k + l*l == N) ans++;
                        if (i*i + j*j + k*k + l*l > N) break;
                    }
                }
            }
        }

        cout << ans << '\n';
    } 
    return 0;
}