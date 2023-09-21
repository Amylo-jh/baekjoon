#include <iostream>

using namespace std;

int two = 0;
int five = 0;

void calc(int n)
{
    while(n % 2 == 0)
    {
        two++;
        n /= 2;
    }

    while(n % 5 == 0)
    {
        five++;
        n /= 5;
    }
}



int main()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        calc(i);
    }

    cout << min(two, five);
}