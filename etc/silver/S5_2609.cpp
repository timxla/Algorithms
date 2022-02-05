#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    while (a != b)
    {
        if (a > b) a -= b;
        else b -= a;
    }
    return a;
}

int lcm(int a, int b)
{
    int max = (a > b) ? a : b; 
    do 
    {
        if (max % a == 0 && max % b == 0)
        {
            return max;
        }
        else
            max++;
    } while (true);
}

int main()
{
    int n1, n2;

    cin >> n1 >> n2;

    cout << gcd(n1, n2) << endl;
    cout << lcm(n1, n2) << endl;

    return 0;
}