#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;

    int arr1[3], arr2[3];

    for (int i = 0; i < 3; ++i)
    {
        arr1[i] = A%10;
        A /= 10;
        arr2[i] = B%10;
        B /= 10;
    }
    
    int revA, revB = 0;
    for (int i = 0; i < 3; ++i)
    {
        revA += (arr1[i]*(pow(10, (2-i))));
        revB += (arr2[i]*(pow(10, (2-i)))); 
    }

    if (revA > revB)
        cout << revA << "\n";
    else
        cout << revB << "\n";
    
    return 0;
}

#include <iostream>
using namespace std;

int rev(int n)
{
    int a, b, c, d;
    a = n%10;
    b = (n/10)%10;
    c = n/100;
    d = a*100 + b*10 + c;
    return d;
}

int main()
{
    int A, B;
    int C, D;
    cin >> A >> B;
    C = rev(A);
    D = rev(B);
    if (C > D) cout << C;
    else cout << D;
    return 0;
}
