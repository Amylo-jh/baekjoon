#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, count = 0;;
    cin >> n;
    n /= 3;
    for(int i = 1; i <= n-2; i++)
    {
        for(int j = 1; j <= n-1-i; j++)
        {
            count++;
        }
    }

    cout << count;
}