#include <iostream>

using namespace std;

int main()
{
    int n, count = 0;
    cin >> n;
    while (n != 1)
    {
        if (n % 2)
        {
            n = n * 3 + 1;
        }
        else
        {
            n /= 2;
        }
        count++;
    }
    cout << count;
}