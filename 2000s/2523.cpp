#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int i = 1;
    for(; i <= n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    i--;
    for(; i > 1; i--)
    {
        for(int j = 0; j < i - 1; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}