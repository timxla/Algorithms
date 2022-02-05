// 이모티콘
// BFS
#include <iostream>
#include <queue>

using namespace std;

int S, scr, clip, sec;
// visited[screen][clipboard]
bool V[2001][2001] = { 0 };
// bfs queue
queue<pair<pair<int, int>, int> > Q;

int emojibfs()
{
    // Initialization (1 emoji on screen, 0 on clipboard, 0 seconds passed)
    Q.push(make_pair(make_pair(1, 0), 0));
    V[1][0] = true;

    while (!Q.empty())
    {
        // save the topmost elements and pop it
        scr = Q.front().first.first;
        clip = Q.front().first.second;
        sec = Q.front().second;
        Q.pop();

        // If we found that number of emojies = what we're looking for return the time in seconds
        if (scr == S) return sec;

        // #1 && #3
        if (scr > 0 && scr < 2000)
        {
            if (V[scr][scr] == false)
            {
                Q.push(make_pair(make_pair(scr, scr), sec+1));
                V[scr][scr] = true;
            }

            if (V[scr-1][clip] == false)
            {
                Q.push(make_pair(make_pair(scr-1, clip), sec+1));
                V[scr-1][clip] = true;
            }
        }

        // #2
        // scr + clip has to be less than 2000
        if (clip > 0 && scr+clip < 2000)
        {
           if (V[scr+clip][clip] == false)
           {
                Q.push(make_pair(make_pair(scr+clip, clip), sec+1));
                V[scr+clip][clip] = true;
           }
        } 
    }
}

int main()
{
    cin >> S;
    int ans = emojibfs();
    cout << ans << '\n';
    return 0;
}