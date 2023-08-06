#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int g, s, e;
        cin >> g >> s >> e;

        s = max(0, e-s);
        if(g == 1)
        {
            cout << s;
        }
        else if(g == 2)
        {
            cout << s*3;
        }
        else
        {
            cout << s*5;
        }
        cout << "\n";
    }
}