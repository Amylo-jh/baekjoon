#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int a, b;
        cin >> b >> a;

        cout << 2*a - b << " " << a - (2*a - b) << "\n";
    }
}