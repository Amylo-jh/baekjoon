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
        a /= b;
        cout << a*a << "\n";
    }
}