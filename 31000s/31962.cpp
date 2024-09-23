#include <iostream>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    int max_bus = -1;

    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if(a + b <= x)
        {
            max_bus = max(max_bus, a);
        }
    }

    cout << max_bus << endl;
}