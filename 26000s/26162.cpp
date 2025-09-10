#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    vector <bool> prime(119, true);
    prime[0] = prime[1] = false;
    for(int i = 0; i <= 118; i++)
    {
        if(prime[i])
        {
            for(int j = i*2; j <= 118; j += i)
            {
                prime[j] = false;
            }
        }
    }
    while(tc--)
    {
        int n;
        cin >> n;
        bool flag = false;
        for(int i = 2; i <= n; i++)
        {
            if(prime[i])
            {
                if(prime[n-i])
                {
                    cout << "Yes\n";
                    flag = true;
                    break;
                }
            }
        }

        if(!flag)
        {
            cout << "No\n";
        }
    }
}