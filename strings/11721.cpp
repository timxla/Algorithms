#include <iostream>
#include <string>

using namespace std;

string aa;

int main()
{
    getline(cin, aa);

    for (int i = 0; i < aa.length(); i = i+10)
    {
        cout << aa.substr(i, 10) << endl;
    }
    return 0;
}