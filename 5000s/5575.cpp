#include <iostream>

using namespace std;

int main()
{
    int tc = 3;
    while(tc--)
    {
        int h1, m1, s1, h2, m2, s2;
        cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;

        int t1 = h1 * 3600 + m1 * 60 + s1;
        int t2 = h2 * 3600 + m2 * 60 + s2;

        int t = t2 - t1;
        int h = t / 3600;
        t %= 3600;
        int m = t / 60;
        t %= 60;
        int s = t;

        cout << h << " " << m << " " << s << "\n";
    }
}