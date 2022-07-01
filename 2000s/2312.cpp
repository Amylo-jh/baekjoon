#include <iostream>
#include <vector>
#include <set>

using namespace std;

void sol(int n)
{
    multiset <int> primes;

    int i = 2;
    while(i <= n)
    {
        if(n % i == 0)
        {
            primes.insert(i);
            n = n / i;
            i = 2;
            continue;
        }
        i++;
    }

    int curr_num = 1;
    for(auto& iter : primes)
    {
        if(iter != curr_num)
        {
            int k = primes.count(iter);
            cout << iter << " " << k << endl;
            curr_num = iter;
        }
    }
}

int main()
{
    int tc;
    cin >> tc;

    for(int i = 0; i < tc; i++)
    {
        int n;
        cin >> n;
        sol(n);
    }
}