// Before using two functions i couldn't get it right
// sometimes using two functions can be more straightforward and clear
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int T;
string par;

bool checker(string str)
{
    int len = str.length();
    stack<char> stk;
    for (int i = 0; i < len; ++i)
    {
        char c = str[i];
        if (c == '(')
        {
            stk.push(c);
        }
        else
        {
            if (stk.empty())
            {
                return false;
            }
            else
            {
                stk.pop();
            }
        }
    }
    if (stk.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        cin >> par;
        if (checker(par))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}