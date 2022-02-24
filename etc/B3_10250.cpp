#include <iostream>

using namespace std;

int hotel[101][101];

int main()
{
    int T;
    int W, H, ith;

    cin >> T;

    while (T--)
    {
        cin >> H >> W >> ith;

        for (int i = 0; i < 101; ++i)
        {
            for (int j = 0; j < 101; ++j)
            {
                hotel[i][j] = i * 100 + j;
            }
        }

        int counter = 0;

        for (int i = 1; i <= W; ++i)
        {
            for (int j = 1; j <= H; ++j)
            {
                counter++;
                if (ith == counter) cout << hotel[j][i] << endl;
            }
        }
    }
    return 0;
}