#include <iostream>

using namespace std;    

int main()
{
    int n, m;
    cin >> n >> m;

    int sum = 0;
    int cow = 1;
    while(n % 2 == 1 && m % 2 == 1)
    {
        n = n / 2;
        m = m / 2;
        sum += cow;
        cow *= 4;
    }

    cout << sum << endl;
}