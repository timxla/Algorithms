// 강의실 배정
// Greedy

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, room = 1;
priority_queue<int, vector<int>, greater<int> > s_pq;
pair<int, int> p[200001];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i].first >> p[i].second;
    }

    // sort all pairs from least to greatest
    sort(p, p+n);
    // push the finishing time of the earliest time block to pq
    s_pq.push(p[0].second);

    for (int i = 1; i < n; ++i)
    {
        // If the finishing time of the time block is less than the start of the next time
        if (s_pq.top() <= p[i].first)
        {
            // Then we dont need to add another room, just add on
            s_pq.pop();
            s_pq.push(p[i].second);
        }
        else
        {
            s_pq.push(p[i].second);
            // add a room
            room += 1;
        }
    }

    cout << room << endl;

    return 0;
}