#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n, m, num;
    int ans = 0;
    vector<int> cards;
    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        cin >> num;
        cards.push_back(num);
    }

    for (int i = 0; i < n-2; ++i){
        for (int j = i+1; j < n-1; ++j){
            for (int k = j+1; k < n; ++k){
                if (cards[i]+cards[j]+cards[k] <= m && m - (cards[i]+cards[j]+cards[k]) <= m - ans)
                    ans = cards[i]+cards[j]+cards[k];
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}
