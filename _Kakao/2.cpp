#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> db;
    vector<pair<string, string> > history;

    for (auto log : record)
    {
        int idx = 0;
        vector<string> split;

        for (int i = 0; i < log.length(); ++i) {
            if (log[i] == ' ')
            {   
                split.push_back(log.substr(idx, i-idx));
                idx = i+1;
            }
        }

        if (split[0] != "Leave") {
            db[split[1]] = log.substr(idx);
        }
        else {
            split.push_back(log.substr(idx));
        }
            
        history.push_back(make_pair(split[0], split[1]));
    }

    for (auto iter : history) {
        string action = iter.first;
        string id = iter.second;
        if (action == "Enter") {
            answer.push_back(db[id] + "님이 들어왔습니다.");
        }
        else if (action == "Leave") {
            answer.push_back(db[id] + "님이 나갔습니다.");
        }
    }
    return answer;
}

int main() {
    vector<string> record;
    record.push_back("Enter uid1234 Muzi");
    record.push_back("Enter uid4567 Prodo");
    record.push_back("Leave uid1234");
    record.push_back("Enter uid1234 Prodo");
    record.push_back("Change uid4567 Ryan");

    vector<string> ans = solution(record);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}