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
        if(n % 2)
        {
            cout << n << " is odd\n";
        }
        else
        {
            cout << n << " is even\n";
        }
    }
}