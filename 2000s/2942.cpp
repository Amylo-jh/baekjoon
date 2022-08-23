#include <iostream>

using namespace std;

int get_gcd(int a, int b)
{
    int n;
    if(a < b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    while(b != 0)
    {
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}

int main()
{
    int a, b;
    cin >> a >> b;

    int gcd = get_gcd(a, b);

    for(int i = 1; i <= gcd; i++)
    {
        if(gcd % i == 0)
        {
            cout << i << " " << a/i << " " << b/i << "\n";
        }
    }
}