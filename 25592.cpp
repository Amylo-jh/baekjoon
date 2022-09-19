#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int t = 1;
    int add = 0;

    while(1)
    {
        if(n > t)
        {
            n -= t;
        }
        else if(n == t)
        {
            add = 0;
            break;
        }
        else if(n < t)
        {
            add = t - n;
            break;
        }
        t++;
        n -= t;

        if(n < 0)
        {
            add = 0;
            break;
        }
        t++;
    }

    cout << add;
}