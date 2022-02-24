#include <iostream>
#include <algorithm>

using namespace std;

int a[3][5];

int main()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            a[j][i] = i;
        }
    }
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}