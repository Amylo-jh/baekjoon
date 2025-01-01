#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    bool flag = false;
    if(a == 8 || a == 9)
    {
        if(d == 8 || d == 9)
        {
            if(b == c)
            {
                flag = true;
                cout << "ignore";
            }
        }
    }
    
    if(!flag)
    {
        cout << "answer";
    }
}