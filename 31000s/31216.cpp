#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <bool> num(1000001, true);
    vector <int> primes;
    num[0] = num[1] = false;
    for(int i = 2; i <= 1000000; i++)
    {
        if(num[i])
        {
            primes.push_back(i);
            for(int j = 2; i*j <= 1000000; j++)
            {
                num[i*j] = false;
            }
        }
    }

    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        cout << primes[primes[n-1]-1] << "\n";
    }
}