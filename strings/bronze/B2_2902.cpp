#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string st;
    vector<char> initials;

    cin >> st;
    initials.push_back(st[0]); 

    for (int i = 1; i < st.length(); ++i)
    {
        if (st[i] == '-')
        {
            initials.push_back(st[i+1]);
        }
    }

    for (int i = 0; i < initials.size(); ++i)
    {
        cout << initials[i];
    }
    return 0;
}