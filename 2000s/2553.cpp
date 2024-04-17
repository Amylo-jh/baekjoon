#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long num = 1;

    for(int i = 1; i <= n; i++)
    {
        num *= i;

        while(num % 10 == 0)
        {
            num /= 10;
        }
        num = num % 100000000;
    }

    cout << num % 10;
}