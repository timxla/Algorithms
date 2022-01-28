#include <iostream>
#include <string>

using namespace std;

string eq;
int ans = 0;
string num = "";

int main()
{
    cin >> eq;

    bool metminus = false;

    for (int i = 0; i <= eq.size(); ++i)
    {
        if (eq[i] == '+' || eq[i] == '-' || i == eq.size())
        {

            if (metminus)
            {
                ans -= stoi(num);
                num = "";
            }
            else
            {
                ans += stoi(num);
                num = "";
            }
        }
        else
        {
            num += eq[i];
        }
        
        if (eq[i] == '-')
        {
            metminus = true;
        }
    } 
    cout << ans << endl;
    return 0;
}