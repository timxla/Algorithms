#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {

    int answer = s.size();
    
    for (int i = 1; i <= s.size()/2; ++i)
    {
        string compressed = "";
        int cnt = 1;
        // The first segment
        string segment = s.substr(0, i);

        for (int j = i; j <= s.size(); j += i)
        {
            if (segment == s.substr(j, i))
            {
                cnt += 1;
            }
            else
            {
                if (cnt == 1) compressed += segment;
                else compressed += to_string(cnt) + segment;
                
                segment = s.substr(j, i);
                cnt = 1;
            }
        }

        if (s.size()%i != 0)
        {
            compressed += s.substr((s.size()/i)*i);
        }

        if (compressed.size() < answer) answer = compressed.size();
    }

    return answer;
}

int main()
{
    string s = "aabbaccc";
    cout << solution(s) << endl;
}