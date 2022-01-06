#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    string str;
    int arr[26];

    cin >> str;
    memset(arr, 0, sizeof(arr));
    
    for (int i = 0; i < str.length(); ++i)
    {
        arr[str[i]-97] += 1;
    }

    for (int i = 0; i < 26; ++i)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}