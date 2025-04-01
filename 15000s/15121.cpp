#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    cout << n << ":\n";

    for(int i = 2; i < n; i++)
    {
        if(n % (i*2-1) == 0)
        {
            cout << i << "," << i-1 << "\n";
        }
        else if((n-i) % (i*2-1) == 0)
        {
            cout << i << "," << i-1 << "\n";
        }

        if(n % i == 0)
        {
            cout << i << "," << i << "\n";
        }
    }
}