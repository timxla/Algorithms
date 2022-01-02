#include <iostream>
#define endl '\n'

using namespace std;

// F[0] = 1 (This is used for the special shapes that have horizontal pieces in the middle)
// F[2] = 3 
// F[4] = F[2] * F[2] + F[0] * 2
// F[6] = F[4] * F[2] + F[2] * 2 + F[0] * 2...

// F[N] = F[N - 2] * F[2] + (F[N - 4] * 2) + ... + F[2] * 2 + F[0] * 2

int N;
int width[35];

int main()
{
    cin >> N;

    width[0] = 1;
    width[1] = 0; // odd spaces cannot be filld at all
    width[2] = 3;
    for (int i = 4; i <= N; i = i + 2)
    {
        width[i] = width[i - 2] * width[2];
        for (int j = i - 4; j >= 0; j = j - 2)
        {
            width[i] += (width[j] * 2);
        }
    }

    cout << width[N] << endl;

    return 0;
}