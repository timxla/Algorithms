#include <iostream>
#include <cstdio>

using namespace std;

#define MAXN 10001

int main()
{
    int N = 0;
    scanf("%d", &N);

    int arr[MAXN] = {0, };

    for (int i = 0; i < N; ++i)
    {
        int x = 0;
        scanf("%d", &x);
        arr[x]++;
    }

    for (int i = 0; i < MAXN; ++i)
    {
        while (arr[i]-- != 0)
            printf("%d\n", i);
    }
}

