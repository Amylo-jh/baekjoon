#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if(n < 206)
    {
        cout << 1;
    }
    else if(n < 218)
    {
        cout << 2;
    }
    else if(n < 229)
    {
        cout << 3;
    }
    else
    {
        cout << 4;
    }
}