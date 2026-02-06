#include <iostream>

using namespace std;

int main()
{
    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        if (n >= 5000000)
        {
            cout << int(n * 0.8) << "\n";
        }
        else if (n >= 1000000)
        {
            cout << int(n * 0.9) << "\n";
        }
        else
        {
            cout << n << "\n";
        }
    }
}