#include <iostream>
#include <vector>

using namespace std;

int T, num;
int fib[50];

int main()
{
    cin >> T;

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < 46; ++i)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }

    for (int i = 0; i < T; ++i)
    {
        int n;
        vector<int> result;
        cin >> n;
        
        for (int j = 45; j >= 1; --j)
        {
            if (fib[j] <= n)                       
            {
                n -= fib[j];
                result.push_back(fib[j]);
            }
        }

        for (int k = result.size()-1; k >= 0; --k)
        {
            cout << result[k] << " ";
        }

        cout << endl;
    }
    
    return 0;
}