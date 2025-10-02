#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <bool> is_prime(1000001, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= 1e6; i++)
    {
        if(is_prime[i])
        {
            for(int j = 2; i*j <= 1e6; j++)
            {
                is_prime[i*j] = false;
            }
        }
    }
    
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        if(is_prime[n+1])
        {
            cout << "1\n1 " << n+1 << "\n";
        }
        else
        {
            cout << "0\n";
        }
    }
}