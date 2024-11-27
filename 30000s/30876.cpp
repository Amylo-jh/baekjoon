#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int x = INT32_MAX, y = INT32_MAX;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        if(b < y)
        {
            x = a;
            y = b;
        }
    }

    cout << x << " " << y;
}