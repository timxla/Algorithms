#include <iostream>
#include <algorithm>
#include <cstring>

#define DMAX(A,B) (((A)>(B))?(A):(B)) 
#define TMAX(A,B,C) ( DMAX( (DMAX((A),(B))) , (C)) )
#define DMIN(A,B) (((A)<(B))?(A):(B)) 
#define TMIN(A,B,C) ( DMIN( (DMIN((A),(B))) , (C)) )
#define endl '\n'
using namespace std;

int N;
int tower[100001][3];
int dpmax[2][3];
int dpmin[2][3];

int main()
{
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> tower[i][0] >> tower[i][1] >> tower[i][2];
    }

    for (int i = 1; i <= N; ++i)
    {
        // You only have to remember the max/min values from the previous level
        // dpmax[1][0] : You can only come down from either dpmax[0][0] or dpmax[0][1]
        // choose the max value + add the value on the current level - position
        dpmax[1][0] = DMAX(dpmax[0][0], dpmax[0][1]) + tower[i][0];
        dpmax[1][1] = TMAX(dpmax[0][0], dpmax[0][1], dpmax[0][2]) + tower[i][1];
        dpmax[1][2] = DMAX(dpmax[0][1], dpmax[0][2]) + tower[i][2];

        dpmin[1][0] = DMIN(dpmin[0][0], dpmin[0][1]) + tower[i][0];
        dpmin[1][1] = TMIN(dpmin[0][0], dpmin[0][1], dpmin[0][2]) + tower[i][1];
        dpmin[1][2] = DMIN(dpmin[0][1], dpmin[0][2]) + tower[i][2];

        // Update dp arrays
        // You have to shift all values in dp[1][?] up to dp[0][?] and continue
        for (int j = 0; j < 3; ++j)
        {
            dpmax[0][j] = dpmax[1][j];
            dpmin[0][j] = dpmin[1][j];
        }
    }

    cout << TMAX(dpmax[1][0], dpmax[1][1], dpmax[1][2]) << " " << TMIN(dpmin[1][0], dpmin[1][1], dpmin[1][2]) << endl;

    return 0;
}