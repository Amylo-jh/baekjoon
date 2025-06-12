#include <iostream>

using namespace std;

int main()
{
    int n, m, sx, sy, ex, ey;
    cin >> n >> m >> sx >> sy >> ex >> ey;

    if(n == 1 || m == 1)
    {
        if(sx == ex && sy == ey)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        return 0;
    }
    
    if((sx+sy)%2 == (ex+ey)%2)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}