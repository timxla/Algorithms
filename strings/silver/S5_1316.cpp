#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int T, j;
int sav, ans;
int A[26];
string str;

int main()
{
    cin >> T;
    ans = 0;

    for (int i = 0; i < T; ++i)
    {
        cin >> str;
        if (str.length() == 1)
        {
            ans++;
            continue;
        }
        memset(A, 0, sizeof(A));

        sav = str[0] - 97;
        A[sav]++;

        for (j = 1; j < str.length(); ++j)
        {
            int digit = str[j]-97;
            if (A[digit] == 0)
            {
                A[digit]++;
                sav = digit;
            }
            else
            {
                if (sav == digit)
                {
                    A[digit]++;
                    sav = digit;
                }
                else
                {
                    break;
                }
            }
        }
        if (j == str.length())
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}