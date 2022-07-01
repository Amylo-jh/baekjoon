#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    int d, e, f;
    int x, y;

    // ax + by = c;
    // dx + ey = f;


    cin >> a >> b >> c >> d >> e >> f;

    for(int i = -999; i <= 999; i++)
    {
        x = i;
        for(int j = -999; j <= 999; j++)
        {
            y = j;

            if((a *x + b * y == c) && (d * x + e * y == f))
            {
                cout << x << " " << y;
                return 0;
            }
        }
    }
}

    /*
    if (a && b && d && e == 0)
    {
        if (a == 0)
        {
            y = c / b;
            if ((f - e * y) == 0)
            {
                x = 0;
            }
            else
            {
                x = (f - e * y) / d;
            }
        }
        if (b == 0)
        {
            x = c / a;
            if ((f - d * x) == 0)
            {
                y = 0;
            }
            else
            {
                y = (f - d * x) / e;
            }
        }
        if (d == 0)
        {
            y = f / e;
            if ((c - b * y) == 0)
            {
                x = 0;
            }
            else
            {
                x = (c - b * y) / a;
            }
        }
        if(e == 0)
        {
            x = f / d;
            if((c - a*x) == 0)
            {
                y = 0;
            }
            else
            {
                y = (c - a*x) / b;
            }
        }

        cout << x << " " << y;
        return 0;
    }

    int tempa = a;
    int tempd = d;

    d = d * a;
    e = e * a;
    f = f * a;

    a = a * tempd;
    b = b * tempd;
    c = c * tempd;

    b = b - e;
    c = c - f;

    y = c / b;

    x = (f - e * y) / d;

    cout << x << " " << y;

    */



