#include <iostream>

using namespace std;

int main()
{
    while(1)
    {
        int n, a, c, tree = 1;
        cin >> n;
        if(n == 0)
        {
            break;
        }
        while(n--)
        {
            cin >> a >> c;
            tree *= a;
            tree -= c;
        }
        cout << tree << "\n";
    }
}