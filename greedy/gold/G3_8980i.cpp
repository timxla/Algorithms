#include <iostream>
#include <algorithm>
using namespace std;

typedef struct
{
    int start;
    int end;
    int weight;

}delivery;

// N = number of cities
// C = Truck capacity
// M = How many different delivery tasks?
int N, C, M;

// capacity is for keeping track of how much load you're gonna have per delivery
int capacity[2001] = {0};
delivery arr[10001];

// This func is used to sort start - end points
// In earliest endpoint arrival order.
bool comp(delivery a, delivery b)
{
    if (a.end == b.end) return (a.start < b.start);
    if (a.end > b.end) return false;
    else return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;
    cin >> M;
    
    for (int i = 0; i < M; ++i)
    {
        cin >> arr[i].start >> arr[i].end >> arr[i].weight;
    }

    sort(arr, arr+M, comp);

    int ans = 0;
    
    // If first delivery is load 30 from city 1 to city 3 
    // temp = 0, leftover = minimum value between 30 and C - temp which is 40 so leftover = 30
    // So you deliver everything!
    // Then add 30 to capacity of city 1 and city 2
    // So in the next loop you have only 10 leftover space when you're in city 1 and 2
    for (int i = 0; i < M; ++i)
    {
        int temp = 0;
        for (int j = arr[i].start; j < arr[i].end; ++j)
        {
            temp = max(temp, capacity[j]);
        }
        int leftover = min(arr[i].weight, C - temp);
        ans += leftover;
        for (int j = arr[i].start; j < arr[i].end; ++j)
        {
            capacity[j] += leftover;
        }
    }
    
    cout << ans << endl;

    return 0;
}