#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int n;
        cin >> n;
        while(n--)
        {
            int a, b;
            cin >> a >> b;
            cout << a+b << " " << a*b << "\n";
        }
    }
}