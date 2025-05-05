#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    cout << 100 - (100-n)*5 << "\n";
    if(n == 100)
    {
        cout << 0;
    }
    else if(n < 100)
    {
        cout << 1;
    }
    else
    {
        cout << -1;
    }
}