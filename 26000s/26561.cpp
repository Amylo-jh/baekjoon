#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n, m;
        cin >> n >> m;
        n -= (m / 7);
        n += (m / 4);
        cout << n << "\n";
    }
}