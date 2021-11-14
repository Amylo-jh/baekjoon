#include <iostream>

using namespace std;

int main()
{
    long long a[5];
    long long total = 0;

    for(int i = 0; i < 5; i++)
    {
        cin >> a[i];
        total = total + a[i];
    }

    cout << total;
}