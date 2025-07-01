#include <iostream>

using namespace std;

int main()
{
    int a, b, c = 0;
    cin >> a >> a >> b;

    while(1)
    {
        if(a == b)
        {
            cout << c;
            return 0;
        }
        a = (a+1)/2;
        b = (b+1)/2;
        c++;
    }
}