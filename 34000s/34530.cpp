#include <iostream>

using namespace std;

int main()
{
    int d, total = 0, c = 1;
    cin >> d;
    total = d;
    while(total % 360)
    {
        total += d;
        c++;
    }
    cout << c;
}