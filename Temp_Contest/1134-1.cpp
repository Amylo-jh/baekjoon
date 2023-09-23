#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int a, b, x;
        cin >> a >> b >> x;
        cout << a*(x-1) + b << "\n";
    }
}