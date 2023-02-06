#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector <bool> prime(100001);
    vector <int> primes;
    for(int i = 2; i <= 100000; i++)
    {
        prime[i] = true;
    }
    for(int i = 2; i <= 100000; i++)
    {
        if(prime[i])
        {
            primes.push_back(i);
            int j = 2;
            while(i*j <= 100000)
            {
                prime[i*j] = false;
                j++;
            }
        }
    }
    int index;
    int prime_size = primes.size();
    for(int i = 0; i < prime_size; i++)
    {
        if(primes[i] > k)
        {
            index = i;
            break;
        }
    }

    int count = min(n, k);
    for(int i = k+1; i <= n; i++)
    {
        bool is_sejun_num = true;
        for(int j = index; j < prime_size && primes[j] <= i; j++)
        {
            if(i % primes[j] == 0)
            {
                is_sejun_num = false;
                break;
            }
        }

        if(is_sejun_num)
        {
            count++;
        }
    }

    cout << count;
}