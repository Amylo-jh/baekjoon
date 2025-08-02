#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++)
    {
        if(n%i)
        {
            cout << i << " ";
            break;
        }
    }
    for(int i = n-1; i > 0; i--)
    {
        if(n%i)
        {
            cout << i;
            break;
        }
    }
}