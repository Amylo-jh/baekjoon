#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int a, b;
        cin >> a >> b;
        cout << lcm(a, b) << " " << gcd(a, b) << "\n";
    }
}