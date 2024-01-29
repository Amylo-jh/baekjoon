#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a = 1000, b = 1000;
    for(int i = 0; i < m; i++)
    {
        int aa, bb;
        cin >> aa >> bb;
        a = min(a, aa);
        b = min(b, bb);
    }

    int cost1 = 0, cost2 = 0, cost3 = 0;
    
    cost1 = (n/6)*a;
    if(n%6)
    {
        cost1 += a;
    }

    cost2 = (n/6)*a + (n%6)*b;
    cost3 = n*b;

    cout << min(min(cost1, cost2), cost3);
}