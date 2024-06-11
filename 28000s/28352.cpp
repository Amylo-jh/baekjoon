#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long week = 6;

    for(int i = 11; i <= n; i++)
    {
        week *= i;
    }

    cout << week << '\n';
}