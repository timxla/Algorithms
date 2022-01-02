#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[501];
// indegree
int ind[501];
int result[501];
// int time[501] error
int Time[501];
int N;
 
int main() {

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> Time[i];
        // The last number of hours added is always itself
        result[i] = Time[i];        
        while (1) {
            int x;  
            cin >> x;
            if (x == -1) break;
            else {
                // graph[x] contains a vector which are nodes that x is being pointed from
                graph[x].push_back(i);
                ind[i]++;
            }
        }
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        // If indegree of ith node is 0 then it can be executed right away
        // Add to queue
        if (ind[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        // for each int in vector (graph[x] = vector<int> [x, y, z...])
        for (int nx : graph[x]) {        
            // result[] can be itself, or the pointing node's original value + time[itself]
            result[nx] = max(result[nx], result[x] + Time[nx]);
            // if the previous calculations resulted in creating a node of indegree 0
            // push that node in the queue (this node is a node that can has no restrictions; 
            // that means that it can be built right away now)
            if (--ind[nx] == 0) {                
                q.push(nx);            
            }
        }
    }

    // Print all updated values
    for (int i = 1; i <= N; i++) {
        cout << result[i] << '\n';
    }

    return 0;
}
