#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        long long money;
        cin >> money;
        int option;
        cin >> option;
        for(int i = 0; i < option; i++)
        {
            long long p, q;
            cin >> p >> q;
            money += p*q;
        }

        cout << money << '\n';
    }
}