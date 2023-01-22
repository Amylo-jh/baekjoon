#include <iostream>

using namespace std;

int main()
{
    int k;
    cin >> k;

    int n = 1;
    int count = 0;

    while (n < k)
    {
        n *= 2;
    }

    cout << n << " ";

    while(n != k)
    {
        if(n/2 < k)
        {
            n /= 2;
            k -= n;
            count++;
        }
        else
        {
            n /= 2;
            count++;
        }
    }

    cout << count;
}