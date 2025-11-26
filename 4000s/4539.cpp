#include <iostream>

using namespace std;

int main()
{
    int tc, n, tmp;
    cin >> tc;
    while(tc--)
    {
        tmp = 10;
        cin >> n;
        if(n < 10)
        {
            cout << n << "\n";
            continue;
        }

        for(int i = 0; i < 7; i++)
        {
            if(n >= tmp)
            {
                n = (n + 5*tmp/10) / tmp * tmp;
            }
            tmp *= 10;
        }
        cout << n << "\n";
    }
}