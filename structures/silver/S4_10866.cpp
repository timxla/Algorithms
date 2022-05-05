#include <iostream>
#include <deque>
#include <string>
#define endl '\n'
using namespace std;

int N, tmp;
string query;
deque<int> deq;


int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> query;
        
        if (query == "push_back")
        {
            cin >> tmp;
            deq.push_back(tmp);
        }
        else if (query == "push_front")
        {
            cin >> tmp;
            deq.push_front(tmp);
        }
        else if (query == "front")
        {
            if (!deq.empty())
            {
                cout << deq.front() << endl;
            }
            else cout << -1 << endl;
        }
        else if (query == "back")
        {
            if (!deq.empty())
            {
                cout << deq.back() << endl;
            }
            else cout << -1 << endl;
        }
        else if (query == "size")
        {
            cout << deq.size() << endl;
        }
        else if (query == "empty")
        {
            cout << deq.empty() << endl;
        }
        else if (query == "pop_front")
        {
            if (!deq.empty())
            {
                tmp = deq.front();
                deq.pop_front();
                cout << tmp << endl;
            }
            else cout << -1 << endl;
        }
        else if (query == "pop_back")
        {
            if (!deq.empty())
            {
                tmp = deq.back();
                deq.pop_back();
                cout << tmp << endl;
            }
            else cout << -1 << endl;
        }
    }
    return 0;
}