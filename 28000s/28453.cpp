#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int level;
        cin >> level;

        if(level >= 300)
        {
            cout << 1;
        }
        else if(level >= 275)
        {
            cout << 2;
        }
        else if(level >= 250)
        {
            cout << 3;
        }
        else
        {
            cout << 4;
        }
        cout << " ";
    }
}