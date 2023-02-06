#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <bool> sieve(100001);
    vector <int> prime;
    int n, k;
    cin >> n >> k;

    sieve.assign(100001, true);
    sieve[0] = false;
    sieve[1] = false;
    for(int i = 2; i <= 100000; i++)
    {
        if(sieve[i])
        {
            if(i > k)
            {
                prime.push_back(i);
            }
            
            for(int j = 2; i*j <= 100000; j++)
            {
                sieve[i*j] = false;
            }
        }
    }

    int count = min(n, k);
    for(int i = k+1; i <= n; i++)
    {
        bool flag = true;
        for(int j : prime)
        {
            if(j > i)
            {
                break;
            }
            if(i % j == 0)
            {
                flag = false;
                break;
            }
        }

        if(flag)
        {
            count++;
        }
    }

    cout << count;
}