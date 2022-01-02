// Change
// dp
#include <iostream>
#include <algorithm>

using namespace std;

int n, five, ans = 0;

int main()
{
    cin >> n;

    // there is no change for 1 won and 3 won.
    if (n == 1 || n == 3)
    {
        cout << -1 << endl;
        return 0;
    }

    // how many "five" coins can fit in n?
    five = n / 5;

    while (true)
    {
        // subtract the price of sum of all "five" coins from n
        // tmp = the leftover money after all "five" coins are removed
        int tmp = n - (5 * five);

        // if the leftover money is even
        if (tmp % 2 == 0)
        {
            // add number of "five" coins taken away + number of "two" coins
            ans = ans + five + (tmp / 2);
            break;
        }

        // if its odd then you have to backtrack and add five to the total price
        // which means you have to remove one "five" coin from the pile you took out earlier
        --five;
    }

    cout << ans << endl;

    return 0;
}