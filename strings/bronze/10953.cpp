#include <iostream>
#include <string>

using namespace std;

string info;
int T, A, B;

int main()
{
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        cin >> info;

        A = info[0];
        B = info[2];
        
        cout << (A+B-96) << endl;
    }

    return 0;
}