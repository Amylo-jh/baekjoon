#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int counter = 0;
    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0)
        {
            counter++;
        }
        if(counter == m)
        {
            cout << i;
            return 0;
        }
    }
    cout << 0;
}