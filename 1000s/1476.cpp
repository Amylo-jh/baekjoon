#include <iostream>

using namespace std;

int main()
{
    int e, s, m, i;
    cin >> e >> s >> m;
    s %= 28;
    m %= 19;
    i = e;
    while (1)
    {
        if (i % 28 == s && i % 19 == m)
        {
            cout << i;
            break;
        }
        i += 15;
    }
}