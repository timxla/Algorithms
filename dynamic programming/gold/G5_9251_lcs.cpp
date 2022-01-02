#include<iostream>
#include<string>
#include<cstring>
 
#define endl "\n"
#define MAX 1001
using namespace std;
 
char A[MAX], B[MAX];
int DP[MAX][MAX];
 
int Bigger(int A, int B) { if (A > B) return A; return B; }
 
void Input()
{
    cin >> A >> B;
}
 
void Solution()
{
    int A_Size = strlen(A);
    int B_Size = strlen(B);
 
    for (int i = 1; i <= A_Size; i++)
    {
        for (int j = 1; j <= B_Size; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                DP[i][j] = DP[i - 1][j - 1] + 1;
                
            }
            else
            {
                DP[i][j] = Bigger(DP[i - 1][j], DP[i][j - 1]);
            }
    
        }
    }
 
    for (int i = 1; i <= A_Size; i++)
    {
       for (int j = 1; j <= B_Size; j++)
       {
           cout << "DP[" << i << "][" << j << "] = " << DP[i][j] << " ";
       }
       cout << endl;
    }
    cout << DP[A_Size][B_Size] << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
