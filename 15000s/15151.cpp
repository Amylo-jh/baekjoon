#include <iostream>

using namespace std;

int main()
{
    int k, d;
    cin >> k >> d;

    for(int i = 1; d > 0; i++)
    {
        d -= k;
        k *= 2;
        if(d < k)
        {
            cout << i;
            break;
        }
    }
}