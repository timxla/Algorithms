#include <iostream>
#include <string>
using namespace std;

string eye;
int cntleft, cntright;
bool flag;

int main()
{
    cin >> eye;
    cntleft = 0;
    cntright = 0;
    flag = 0;
    for (int i = 0; i < eye.size(); ++i)
    {
        if (flag == 0)
        {
            if (eye[i] == '|')
            {
                cntleft++;
            }

        }
        else
        {
            if (eye[i] == '|')
            {
                cntright++;
            }
        }
        if (eye[i] == ')')
        {
            flag = 1;
        }
    }

    if (cntleft == cntright)
    {
        cout << "correct" << endl;
    }
    else
    {
        cout << "fix" << endl;
    }
    return 0;
}