#include <iostream>

using namespace std;

int main()
{
    int a, b, c, m;
    cin >> a >> b >> c >> m;

    int work = 0;
    int tired = 0;
    for(int i = 0; i < 24; i++)
    {
        if(tired + a <= m)
        {
            tired += a;
            work += b;
        }
        else
        {
            tired -= c;
            if(tired < 0)
                tired = 0;
        }
    }

    cout << work;
}