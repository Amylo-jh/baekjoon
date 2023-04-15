#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b, op;
    cin >> a >> op >> b;

    if(op == "*")
    {
        int len = a.length() + b.length() - 2;
        cout << 1;
        for(int i = 0; i < len; i++)
        {
            cout << 0;
        }
    }
    else
    {
        int len = max(a.length(), b.length());
        for(int i = len; i > 0; i--)
        {
            if(i == len && a.length() == b.length())
            {
                cout << 2;
                continue;
            }
            if(i == a.length() || i == b.length())
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }
    }
}