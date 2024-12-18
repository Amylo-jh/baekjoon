#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;

        int count = 0;
        for(int i = 1; i <= sqrt(n); i++)
        {
            if(n % i == 0)
            {
                int b = n / i;
                if(b < i)
                {
                    break;
                }
                if(gcd(i, b) == 1)
                {
                    count++;
                }
            }
        }

        cout << count << '\n';
    }
}