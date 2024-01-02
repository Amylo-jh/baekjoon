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
        int divider = n % 100;
        n++;
        if(n % divider == 0)
        {
            cout << "Good\n";
        }
        else
        {
            cout << "Bye\n";
        }
    }
}