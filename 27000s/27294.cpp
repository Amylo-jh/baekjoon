#include <iostream>

using namespace std;

int main()
{
    int t, s;
    cin >> t >> s;

    if(12 <= t && t <= 16 && s == 0)
    {
        cout << 320;
    }
    else
    {
        cout << 280;
    }
}