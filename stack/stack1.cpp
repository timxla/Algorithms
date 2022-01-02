#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    stack<int> s;
    int N;
    cin >> N;
    vector<int> ans;
    
    for (int i = 0; i < N; i++)
    {
        string command;
        cin >> command;
        if (!command.compare("push"))
        {
            int value;
            cin >> value;
            s.push(value);
        }
        else if (!command.compare("top"))
        {
            if (s.empty())
                ans.push_back(-1);
            else{
                ans.push_back(s.top());
            }
        }
        else if (!command.compare("size"))
        {
            ans.push_back(s.size());
        }
        else if (!command.compare("pop"))
        {
            if (s.empty())
                ans.push_back(-1);
            else{
                ans.push_back(s.top());
                s.pop();
            }
        }
        else if (!command.compare("empty"))
        {
            if (s.empty())
                ans.push_back(-1);
            else{
                ans.push_back(0);
            }
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }
    
    return 0;
}
