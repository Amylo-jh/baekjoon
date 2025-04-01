#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        string a, b;
        cin >> a >> b;
        if(a != b)
        {
            cout << "ERROR\n";
        }
        else
        {
            cout << "OK\n";
        }
    }
}