#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct info
{
    int age;
    string name;
    int order;
};

info names[100001];

bool comp(info a, info b)
{
    if (a.age < b.age)
    {
        return true;
    }
    else if (a.age == b.age)
    {
        return (a.order < b.order);
    }
    else return false;
}

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        cin >> names[i].age >> names[i].name;
        names[i].order = i+1;
    }

    sort(names, names+T, comp);

    for (int i = 0; i < T; ++i)
    {
        cout << names[i].age << ' ' << names[i].name << '\n';
    }

    return 0;
}