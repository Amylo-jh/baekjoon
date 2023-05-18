#include <iostream>

using namespace std;

int main()
{
    long long num = 1;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        num *= i;
    }

    cout << num;
}