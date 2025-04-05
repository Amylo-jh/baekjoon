#include <iostream>

using namespace std;

int main()
{
    long long n, num = 1;
    cin >> n;
    while(num <= n)
    {
        if(num == n)
        {
            cout << "1";
            return 0;
        }
        num *= 2;
    }

    cout << "0";
}