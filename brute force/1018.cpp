#include <iostream>
#include <string>

using namespace std;

int main(){
    int entry, strlen, ans;
    int BWc, WBc;
    cin >> entry >> strlen;

    string BW[8] = {"BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB"};
    string WB[8] = {"WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW"};
    
    string arr[entry];
    for (int i = 0; i < entry; ++i){
        cin >> arr[i];
    }
    
    // 8 8 = 1 1
    // 9 9 = 2 2
    // 10 13 = 3 6
    ans = 64;

    for (int sp_strlen = 0; sp_strlen < strlen-7; sp_strlen++){
        for (int sp_entry = 0; sp_entry < entry-7; sp_entry++){
            BWc = 0;
            WBc = 0;
            for (int i = sp_strlen; i < sp_strlen+8; ++i){
                for (int j = sp_entry; j < sp_entry+8; ++j){
                    if (BW[j-sp_entry][i-sp_strlen] != arr[j][i])
                        BWc += 1;
                    if (WB[j-sp_entry][i-sp_strlen] != arr[j][i])
                        WBc += 1;
                }
            }
            if (ans > BWc)
                ans = BWc;
            if (ans > WBc)
                ans = WBc;
        }
    }

    cout << ans << endl;

    return 0; 
}
