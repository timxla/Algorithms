#include <iostream>
#include <cmath>
using namespace std;

void hanoitower(int rings, char from, char mid, char to){
    if (rings == 1){
        cout << from << " " << to << "\n";
        return;
    }

    else{
        hanoitower(rings-1, from, to, mid);
        cout << from << " " << to << "\n";
        hanoitower(rings-1, mid, from, to);
    }

}

int main(){

    int rings;
    cin >> rings;
    if (rings > 20)
    {
        cout << (pow(2, rings)-1) << "\n";
        return 0;
    }
    else
    {
        cout << (pow(2, rings)-1) << "\n";
        hanoitower(rings, '1', '2', '3');
    }
    return 0;
}
