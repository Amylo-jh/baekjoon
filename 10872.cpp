#include <iostream>

using namespace std;

int main()
{
    int n;
    int total = 1;

    cin >> n;

    for(int i = n; i > 1; i--)
    {
        total = total * i;
    }
    cout << total;
}