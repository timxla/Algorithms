// How many moves to reassign othello positions?

#include <iostream>
#include <string>
using namespace std;

int N, T;
string before, after;

// these are used to count how many whites, blacks you have to change
int white, black;

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        white = 0;
        black = 0;

        cin >> T;
        cin >> before >> after;

        for (int j = 0; j < T; ++j)
        {
            if (before[j] != after[j])
            {
                if (before[j] == 'W')
                {
                    white++;
                }
                else
                {
                    black++;
                }
            }
        }
        // Okay so this is the important part.
        // you count the number of different pieces, but if the original was white then white++.. vice versa
        // the answer is the greater of the two
        // equation : if white = 2 and black = 1, then one white and one black can be switched, so you can save a flip turn
        // then the remainder must be added (if white = 3 and black = 1 then answer is 3 because there is only one pair)
        if (white > black) 
        {
            cout << white << endl;
        }
        else 
        {
            cout << black << endl;
        }
    }
    return 0;
}