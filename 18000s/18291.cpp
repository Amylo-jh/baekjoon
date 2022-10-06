#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    for(int q = 0; q < tc; q++)
    {
        int n;
        cin >> n;
        n -= 2;
        if(n <= 0)
        {
            cout << 1 << '\n';
            continue;
        }
        else
        {
            long long res = 1;
            long long c = 2;
            while(n)
            {
                if(n & 1)
                {
                    res *= c;
                    res %= 1000000007;
                }
                c *= c;
                c %= 1000000007;
                n = n >> 1;
            }

            cout << res << "\n";
        }
    }
}