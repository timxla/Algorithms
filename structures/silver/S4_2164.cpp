#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N;
    queue<int> qq;
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        qq.push(i);
    }

    while (qq.size() > 1)
    {
        qq.pop();
        int top = qq.front();
        qq.push(top);
        qq.pop();
    }

    cout << qq.front() << endl;
    return 0;
}