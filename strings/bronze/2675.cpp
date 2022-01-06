#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int loop, num;
    int arr[1000] = {0,};
    string data;
    vector<string> pstr;

    cin >> loop;

    for (int i = 0; i < loop; ++i){
        cin >> num >> data;
        arr[i] = num;
        pstr.push_back(data);
    }
    
    //cout << pstr[0][0] << "\n"; = A
    //cout << pstr[1] << "\n"; = ABC

    //cout << arr[0] << "\n"; 2
    //cout << arr[1] << "\n"; 3

    //cout << pstr[0].size() << "\n"; = 3
    //
    for (int i = 0; i < loop; ++i){
        for (int j = 0; j < pstr[i].size(); ++j){
            cout << string(arr[i], pstr[i][j]);
        }
        cout << "\n";
    }
    return 0;
}
