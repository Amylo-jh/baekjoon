#include <iostream>

using namespace std;

int main()
{
    int n, h, tmp;
    cin >> n >> h;
    for(int i = 1; i <= n; i++)
    {
        cin >> tmp;
        h -= tmp;
        if(h <= 0)
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}