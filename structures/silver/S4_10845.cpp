#include <iostream>
#include <queue>
#include <string>
#define endl '\n'

using namespace std;

int N;
string query;
queue<int> q;

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> query;
        
        if (query == "front")
        {
            if (!q.empty())
                cout << q.front() << endl;
            else
                cout << -1 << endl;
        }
        else if (query == "back")
        {
            if (!q.empty())
                cout << q.back() << endl;
            else
                cout << -1 << endl;
        }
        else if (query == "pop")
        {
            if (!q.empty())
            {
                int tmp = q.front();
                q.pop();
                cout << tmp << endl;
            }
            else
                cout << -1 << endl;
        }
        else if (query == "size")
        {
            cout << q.size() << endl;
        }
        else if (query == "empty")
        {
            cout << q.empty() << endl;
        }
        else 
        {
            int num; 
            cin >> num;
            q.push(num);
        }
    }

    return 0;
}