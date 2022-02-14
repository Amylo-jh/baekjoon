#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, e, basket = 0;

    cin >> a >> b >> c >> d >> e;

    basket = basket + e;    
    basket = basket + d;

    if(a <= d)
    {
        a = 0;
    }
    else
    {
        a = a - d;
    }

    basket = basket + c;
    if(b <= c)
    {
        c = c - b;
        b = 0;
        a = a - c*2;
    }
    else
    {
        b = b - c;

        basket = basket + b/2 + b%2;
        a = a - b/2;
        if(b%2)
        {
            a = a - 3;
        }  
    }

  

    if(a > 0)
    {
        basket = basket + a/5;
        if(a%5)
        {
            basket++;
        }
    }

    cout << basket;

}