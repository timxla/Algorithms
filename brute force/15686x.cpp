#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, select, totalchicken, place;

struct coord
{
    int x;
    int y;
};

vector<coord> homes;
vector<coord> chicken;

int main()
{
    cin >> n >> select;
    coord a;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> place;
            if (place == 1)
            {
                a.x = i;
                a.y = j;
                homes.push_back(a);
            }
            if (place == 2)
            {
                a.x = i;
                a.y = j;
                chicken.push_back(a);
            }
        }
    }
    totalchicken = chicken.size();
    string bitmask(select, 1);
    bitmask.resize(totalchicken, 0);
    
    do {
        vector<int> comb;
        for (int i = 0; i < totalchicken; ++i)
        {
            if (bitmask[i]) comb.push_back(i);
        }

    } while (prev_permutation(bitmask.begin(), bitmask.end()));




    return 0;
}