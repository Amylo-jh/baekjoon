#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int n;
        bool impossible = true;
        string a, b, target, shuffle = "";
        cin >> n >> a >> b >> target;

        for(int i = 0; i < 2*n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                shuffle += b[j];
                shuffle += a[j];
            }
            if(shuffle == target)
            {
                cout << i+1 << "\n";
                impossible = false;
                break;
            }

            a = shuffle.substr(0, n);
            b = shuffle.substr(n, n);
            shuffle = "";
        }

        if(impossible)
        {
            cout << -1 << "\n";
        }
    }
}