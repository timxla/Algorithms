#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N;
string str;
queue<int> Q;

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;

        if (str[3] == 'h')
        {
            int num = str[5];
            cout << num << endl;
        }
    }
    return 0;
}