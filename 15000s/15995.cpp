#include <iostream>

using namespace std;

int main()
{
    int a, m;
    cin >> a >> m;
    for(int i = 1; i < INT32_MAX; i++)
    {
        if( (a*i) % m == 1)
        {
            cout << i;
            break;
        }
    }
}