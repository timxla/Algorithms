#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
    int N;
    int order, num = 0;
    string key = "666";
    cin >> N;

    while (order != N)
    {
        num += 1;
        string number = to_string(num);
        if (number.find(key) != string::npos)
        {
            order += 1;
        }
    }
    cout << num << endl;
    return 0; 
}
