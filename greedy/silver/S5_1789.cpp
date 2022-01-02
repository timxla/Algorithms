#include <iostream>
#define ll long long

using namespace std;

int main()
{
    ll S;
    cin >> S;

    ll sum = 0;
    ll num = 1;
    ll counter = 0;

    while (true)
    {
        sum += num;
        counter++;
        if (sum > S)
        {
            counter--;
            break;
        }
        num++;
    } 

    cout << counter << endl;
    return 0;
}