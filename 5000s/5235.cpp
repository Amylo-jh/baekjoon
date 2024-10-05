#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int n;
        int a = 0, b = 0;
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            if(x % 2 == 0)
            {
                a += x;
            }
            else
            {
                b += x;
            }
        }

        if(a > b)
        {
            cout << "EVEN";
        }
        else if(a < b)
        {
            cout << "ODD";
        }
        else
        {
            cout << "TIE";
        }
        cout << "\n";
    }
}