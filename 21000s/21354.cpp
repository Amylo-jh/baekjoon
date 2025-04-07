#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    a *= 7;
    b *= 13;

    if(a < b)
    {
        cout << "Petra";
    }
    else if(a > b)
    {
        cout << "Axel";
    }
    else
    {
        cout << "lika";
    }
}