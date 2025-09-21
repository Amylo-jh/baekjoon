#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n == 0)
    {
        cout << 1;
        return 0;
    }
    int tmp = 1;
    int digit = 1;
    while(tmp <= n)
    {
        tmp = tmp*10 + 1;
        digit++;
    }
    cout << digit-1;
}