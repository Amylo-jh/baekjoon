#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int i = 2;
    while(i <= n)
    {
        if(n % i == 0)
        {
            cout << i << endl;
            n = n / i;
            i = 2;
            continue;
        }
        i++;
    }
}