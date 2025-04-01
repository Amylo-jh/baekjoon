#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector <bool> prime(1e6+1, true);
    vector <long long> primes;
    prime[0] = false;
    prime[1] = false;
    for(long long i = 2; i <= 1e6; i++)
    {
        if(prime[i])
        {
            primes.push_back(i);
            for(long long j = 2; i*j <= 1e6; j++)
            {
                prime[i*j] = false;
            }
        }
    }

    if(n <= 1e6 && prime[n])
    {
        cout << 1;
        return 0;
    }

    if(n % 2)
    {
        bool flag = false;
        for(long long i : primes)
        {
            if(n % i == 0)
            {
                flag = true;
                cout << (n-i)/2 + 1;
                break;
            }
        }

        if(!flag)
        {
            cout << 1;
        }
    }
    else
    {
        cout << n/2;
    }
}