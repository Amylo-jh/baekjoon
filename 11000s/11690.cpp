#include <iostream>
#include <vector>

using namespace std;

vector <int> primes;

int main()
{
    long long mod = 4294967296;
    int n;
    cin >> n;

    vector <bool> is_prime(n+1);
    is_prime.assign(n+1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for(int i = 4; i <= n+1; i += 2)
    {
        is_prime[i] = false;
    }
    primes.push_back(2);
    for(int i = 3; i < n+1; i += 2)
    {
        if(is_prime[i])
        {
            primes.push_back(i);
            for(int j = i*2; j <= n+1; j+= i)
            {
                is_prime[j] = false;
            }
        }
    }
    
    long long result = 1;
    for(int i = 0; i < primes.size(); i++)
    {
        long long power = primes[i];
        while(power * primes[i] <= n)
        {
            power *= primes[i];
        }
        result = (result * power) % mod;
    }
    
    cout << result;
}