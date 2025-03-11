#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int a, b;
        cin >> a >> b;
        if(a < 12 || b < 4)
        {
            cout << -1 << "\n";
            continue;
        }
        cout << 11*b + 4 << "\n";
    }
}