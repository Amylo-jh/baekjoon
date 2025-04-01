#include <iostream>

using namespace std;

int main()
{
    double k, p, x;
    cin >> k >> p >> x;

    double price = 1e9;
    for(int i = 1; i <= 100000; i++)
    {
        double curr = (x*i) + (k/i * p);
        if(curr < price)
        {
            price = curr;
        }
        else
        {
            cout << fixed;
            cout.precision(3);
            cout << price;
            break;
        }
    }
}