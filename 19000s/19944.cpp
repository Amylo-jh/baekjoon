#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    if(m <= 2)
    {
        cout << "NEWBIE!";
    }
    else if(m <= n)
    {
        cout << "OLDBIE!";
    }
    else
    {
        cout << "TLE!";
    }
}