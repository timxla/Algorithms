#include<iostream>
#include<string>

using namespace std;

string aa;
 
int main()
{
    while (1)
    {
        getline(cin, aa);

        if (aa == "")
            break;

        cout << aa << endl;
    }
    return 0;
}