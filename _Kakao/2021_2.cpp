#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct pos {
    int x, y, d;
};

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

vector<string> Room;

bool bfs(int row, int col) {
    bool visited[5][5] = {false, };
    queue<pos> q;
    pos tmp = {row, col, 0};
    q.push(tmp);
    visited[row][col] = true;

    while (!q.empty()) {
        int _r = q.front().x;
        int _c = q.front().y;
        int _d = q.front().d;

        q.pop();

        for (int i = 0; i < 4; ++i) {
            int drow = _r + dr[i];
            int dcol = _c + dc[i];

            if (drow >= 5 || drow < 0 || dcol >= 5 || dcol < 0) continue;
            if (visited[drow][dcol] || Room[drow][dcol] == 'X') continue;

            if (Room[drow][dcol] == 'P') {
                if (_d + 1 <= 2) {
                    return 0;
                }
            }
            
            pos tmp2 = {drow, dcol, _d+1};
            q.push(tmp2);
            visited[drow][dcol] = true;
        }
    }
    return 1;
}

int check(vector<string> room) { 

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (room[i][j] == 'P') {
                if (!bfs(i, j)) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string> > places) {
    vector<int> answer;

    for (int i = 0; i < 5; ++i) {
        Room = places[i];
        answer.push_back(check(places[i]));
    }
    return answer;
}
