#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {

    string sn = "";

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= '0' || s[i] <= '9') {
            sn.append(1, s[i]);
        }
        else {
            if (s[i] == 'z') {
                sn.append(1, '0');
                i += 4;
            }
            else if (s[i] == 'o') {
                sn.append(1, '1');
                i += 3;
            }
            else if (s[i] == 't') {
                if (s.substr(i, 3) == "two") {
                    sn.append(1, '2');
                    i += 3;
                }
                else {
                    sn.append(1, '3');
                    i += 5;
                }
            }
            else if (s[i] == 'f') {
                if (s.substr(i, 4) == "four") {
                    sn.append(1, '4');
                    i += 4;
                }
                else {
                    sn.append(1, '5');
                    i += 4;
                }
            }
            else if (s[i] == 's') {
                if (s.substr(i, 3) == "six") {
                    sn.append(1, '6');
                    i += 3;
                }
                else {
                    sn.append(1, '7');
                    i += 5;
                }
            }
            else if (s[i] == 'e') {
                sn.append(1, '8');
                i += 5;
            }
            else if (s[i] == 'n') {
                sn.append(1, '9');
                i += 4;
            }
        }
    }
    return stoi(sn);
}

int main() {
    string str = "onetwo34fiveeight";
    cout << solution(str) << endl;
    return 0;
}