#include <iostream>

using namespace std;

int main()
{
    int d, h, m, s;
    cin >> d >> h >> m;
    s = d*1440 + h*60 + m;
    s -= (11*1440 + 11*60 + 11);
    s = s<0?-1:s;
    cout << s;
}