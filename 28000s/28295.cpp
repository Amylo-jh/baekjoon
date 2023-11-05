#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    for(int i = 0; i < 10; i++)
    {
        int a;
        cin >> a;
        n += a;
    }

    if(n % 4 == 0)
    {
        cout << "N";
    }
    else if(n % 4 == 1)
    {
        cout << "E";
    }
    else if(n % 4 == 2)
    {
        cout << "S";
    }
    else
    {
        cout << "W";
    }
}