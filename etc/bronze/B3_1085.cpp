#include <iostream>
#include <cstdlib>
using namespace std;

int x, y, w, h;

int main()
{
    cin >> x >> y >> w >> h;

    int x_diff = abs(x - w);
    int y_diff = abs(y - h);

    int arr[4] = {x, y, x_diff, y_diff};
    int ans = 1001;

    for (int i = 0; i < 4; ++i)
    {
        if (arr[i] < ans)
        {
            ans = arr[i];
        }
    }

    cout << ans << endl;

    return 0;
}