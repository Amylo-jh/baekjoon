#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    n -= 2;
    if(n % 7 == 0)
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
}