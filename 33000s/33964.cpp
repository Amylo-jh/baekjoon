#include <iostream>

using namespace std;

int main()
{
    int n, tmp, sum = 0;
    cin >> n;
    tmp = 0;
    while (n--)
    {
        tmp *= 10;
        tmp++;
    }
    sum += tmp;
    cin >> n;
    tmp = 0;
    while (n--)
    {
        tmp *= 10;
        tmp++;
    }
    sum += tmp;
    cout << sum;
}