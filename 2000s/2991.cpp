#include <iostream>

using namespace std;

int main()
{
    int a1, a2, b1, b2, p, m, n;
    cin >> a1 >> a2 >> b1 >> b2 >> p >> m >> n;

    int dog = 0;
    if(0 < p % (a1+a2) && p % (a1+a2) <= a1)
    {
        dog++;
    }
    if(0 < p % (b1+b2) && p % (b1+b2) <= b1)
    {
        dog++;
    }
    cout << dog << "\n";
    dog = 0;

    if(0 < m % (a1+a2) && m % (a1+a2)<= a1)
    {
        dog++;
    }
    if(0 < m % (b1+b2) && m % (b1+b2) <= b1)
    {
        dog++;
    }
    cout << dog << "\n";
    dog = 0;

    if(0 < n % (a1+a2) && n % (a1+a2) <= a1)
    {
        dog++;
    }
    if(0 < n % (b1+b2) && n % (b1+b2) <= b1)
    {
        dog++;
    }
    cout << dog << "\n";
}