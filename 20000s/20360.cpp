#include <iostream>

using namespace std;

int main()
{
    int n, i = 0;
    cin >> n;
    while(n)
    {
        if(n % 2)
        {
            cout << i << " ";
        }
        n /= 2;
        i++;
    }
}