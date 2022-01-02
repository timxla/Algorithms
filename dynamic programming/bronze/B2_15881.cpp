#include <iostream>
#include <string>

#define endl '\n'
using namespace std;

int n, ans;
string objects;

int main()
{
    cin >> n;
    cin >> objects;

    for (int i = 0; i < objects.length(); ++i)
    {
        if (objects[i] == 'p') 
        {
            if (objects.substr(i+1, 3) == "PAp")
            {
                ans++;
                i += 3;
            }
            else continue;
        }
    }
    cout << ans << endl;
    return 0;
}