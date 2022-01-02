#include <iostream>
using namespace std;

int main()
{

    int arr[50][2];
    int num, cnt;
    cin >> num;

    int grade[num];

    for (int i = 0; i < num; ++i)
    {
        cin >> arr[i][0] >> arr[i][1]; // saved input into 2d array
    }

    for (int i = 0; i < num; ++i)
    {
        cnt = 0;
        for (int j = 0; j < num; ++j)
        {
            if (i == j)
            {
                continue;
            }
            if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1])
            {
                cnt += 1; 
                continue;
            }
        }
        grade[i] = cnt+1;
    }

    for (int i = 0; i < num; ++i){
        cout << grade[i] << " ";
    }
    cout << endl;
    
    return 0;
}
