#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class point
{
    public:
        int x;
        int y;

        point(int _x, int _y)
        {
            x = _x;
            y = _y;
        }
};

bool compare(point &a, point &b)
{
    if (a.x < b.x)
    {
        return true;
    }
    if (a.x == b.x)
    {
        if (a.y < b.y)
        {
            return true;
        }
        else return false;
    }
    else return false;
}

int main()
{
    int N;
    cin >> N;
    int x, y;
    vector<point> points;
    
    for (int i = 0; i < N; ++i)
    {
        cin >> x >> y;
        points.push_back(point(x, y));
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < n; ++i)
    {
        cout << v[i].x << ' ' << v[i].y << '\n';
    }

    return 0;

}
