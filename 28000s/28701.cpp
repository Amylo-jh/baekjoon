#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += i;
    }
    cout << sum << "\n";

    cout << sum*sum << "\n";
    sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += i*i*i;
    }
    cout << sum << "\n";
}