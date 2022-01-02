#include <iostream>
#include <string>
using namespace std;

int main()
{
    string S;
    cin >> S;
    int counter = 1;
    int marker = S[0];
    for (int i = 1; i < S.length(); ++i)
    {
        if (S[i] == marker)
        {
            continue;
        }
        else
        {
            counter++;
            marker = S[i];
        }
    }
    if (counter % 2 == 0)
    {
        //even
        cout << (counter/2) << endl;
    }
    else{
        // odd
        cout << (counter-1)/2 << endl;
    }
    return 0;
}