#include <iostream>

using namespace std;

long long path(int a, int b)
{
    long long way = 1;

    for(int i = a+1; i <= a+b; i++)
    {
        way = way * i;
    }

    for(int i = 1; i <= b; i++)
    {
        way = way / i;
    }

    return way;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    if(k == 0)
    {
        cout << path(n-1, m-1);
    }
    else
    {
        int middle_x = k % m;
        int middle_y = (k / m) + 1;
        if(middle_x == 0)
        {
            middle_x += m;
            middle_y--;
        }

        cout << path(middle_x-1, middle_y-1) * path(m - middle_x, n - middle_y);
    }
}