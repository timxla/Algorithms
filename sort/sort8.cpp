#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

bool compare(string a, string b)
{
    if (a.length() == b.length())
    {
        return a<b;
    }
    return a.length()<b.length();
}

int main()
{
    int N;
    vector<string> v;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        string word;
        cin >> word;
        if (find(v.begin(), v.end(), word) == v.end())
        {
            v.push_back(word);
        }
    }

    sort(v.begin(), v.end(), compare);
    

    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << '\n';
    }
    return 0;
}
