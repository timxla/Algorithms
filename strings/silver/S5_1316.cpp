#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool flag;
int T;
int sav, ans;
int A[26];
string str;

int main()
{
    cin >> T;
    ans = 0;
    flag = true;

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

        for (int j = 1; j < str.length(); ++j)
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
                    flag = false;
                }
            }
        }
        if (flag)
        {
            ans++;
            flag = true;
        }
    }
    cout << ans << endl;
    return 0;
}