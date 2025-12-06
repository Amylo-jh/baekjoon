#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <bool> is_prime(pow(2, 16)+1, true);
    vector <int> prime;
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i < pow(2, 16); i++)
    {
        if(is_prime[i])
        {
            prime.push_back(i);
            for(int j = 2; i*j <= pow(2, 16); j++)
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
        bool divided = false;
        cin >> n;
        cout << n << ": ";
        for(int i = 0; i < prime.size(); i++)
        {
            if(n % prime[i] == 0)
            {
                if(n == prime[i] && !divided)
                {
                    cout << "prime";
                    divided = true;
                    break;
                }
                divided = true;
                cout << prime[i] << " ";
                n /= prime[i];
                i--;
                if(n == 1)
                {
                    break;
                }
            }
        }
        if(!divided)
        {
            cout << "prime";
        }
        cout << "\n";
    }
}