#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if(n == 3)
    {
        cout << "-1";
    }
    else if (n % 2) //n이 홀수일때
    {
        for(int i = 1; i <= n/2; i++)
        {
            cout << i+1 << "\n";
        }
        cout << "1\n";
        cout << n << "\n";
        for(int i = 1; i < n/2; i++)
        {
            cout << n/2 + i+1 << "\n";
        }
    }
    else // n이 짝수일때
    {
        for(int i = 1; i < n/2; i++)
        {
            cout << i+1 << "\n";
        }
        cout << "1\n";
        cout << n << "\n";
        for(int i = 1; i < n/2; i++)
        {
            cout << n/2 + i << "\n";
        }
    }
}