#include <iostream>

using namespace std;

int main()
{
    int a, b, k;
    cin >> a >> b >> k;
    int team = 0;

    while( (a-2) + (b-1) >= k && a >= 2 && b >= 1)
    {
        a -= 2;
        b -= 1;
        team++;
    }

    cout << team;
}