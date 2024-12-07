#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int n;
        __int128_t total = 0;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            long long temp;
            cin >> temp;
            total += temp;
        }

        if(total % n == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}