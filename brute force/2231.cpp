#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

int main(){

    int num, sum, digit;

    cin >> num;

    for (int i = 0; i < num; ++i){
        sum = i;
        digit = i;

        while (digit > 0){
            sum += digit % 10;
            digit /= 10;
        }
        if (sum == num){
            cout << i << endl;
            return 0;
        }
    }
    cout << "0" << endl;
    
    return 0;
}
