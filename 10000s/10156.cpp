#include <iostream>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    k = n * m - k;

    if(k < 0)
    {
        cout << 0;
    }
    else
    {
        cout << k;
    }
}