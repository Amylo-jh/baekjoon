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

        if(n == 1)
        {
            cout << 1 << endl;
            continue;;
        }

        int digit = 0;

        bool flag = true;
        while(n != 1 && flag)
        {
            for(int i = 9; i >= 1; i--)
            {
                if(i != 1 && n % i == 0)
                {
                    digit++;
                    n = n / i;
                    break;
                }

                if(i == 1)
                {
                    flag = false;
                    break;
                }
            }
        }

        if(flag)
        {
            cout << digit << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}