#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        long long a, c;
        cin >> a >> c;
        while (a)
        {
            a /= 2;
            c++;
        }
        cout << c << "\n";
    }
}