#include <iostream>
#include <string>

using namespace std;

int num;

int main()
{
    while (true)
    {
        cin >> num;
        if (num == 0)
        {
            return 0;
        }

        string S = to_string(num);
        int len = S.size();
        int cnt = 0;
        for (int i = 0; i < len/2; ++i)
        {
            if (S[i] == S[len-i-1])
            {
                cnt++;
            }
        }
        if (cnt == len/2)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
    return 0;
}