#include <iostream>

using namespace std;

int main()
{
    int n;
    int total = 0;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        total = total + i;
    }

    cout << total;
}