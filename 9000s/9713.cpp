#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int n;
        cin >> n;
        cout << (n+1)/2 * (n+1)/2 << "\n";
    }
}