#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int num = 5;

    for(int i = 2; i <= n; i++)
    {
        num += i * 3 + 1;
        num %= 45678;
    }

    cout << num;
}