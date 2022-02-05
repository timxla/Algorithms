#include <iostream>
#include <vector>

using namespace std;

vector<int> createPrimes()
{
    vector<int> primes;
    for (int i = 2; i < 1000; ++i)
    {
        bool prime = true;
        for (int j = 2; j*j <= i; ++j)
        {
            if (i % j == 0)
            {
                prime = false;
                break;
            }
        }
        if (prime)
        {
            primes.push_back(i);
        }
    }
    return primes;
}

int main()
{
    vector<int> primes;
    int N;
    int search[101];

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> search[i];
    }

    primes = createPrimes();

    // then binary search primes to see if there is search[i]

    int low, mid, high, count;
    count = 0;
    for (int i = 0; i < N; ++i)
    {
        low = 0;
        high = primes.size()-1;
        while (low <= high)
        {
            mid = (high + low) / 2;
            if (primes[mid] == search[i])
            {
                count++;
                break;
            }
            else if (primes[mid] > search[i])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            } 
        }
    }   
    
    cout << count << endl;
    return 0;
}