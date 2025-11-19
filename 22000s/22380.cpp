#include <iostream>

using namespace std;

int main()
{
    int n, m, sum, cost, temp;
    while(1)
    {
        cin >> n >> m;
        if(n == 0 && m == 0)
        {
            break;
        }
        cost = m/n;
        sum = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            sum += min(cost, temp);
        }
        cout << sum << "\n";
    }
}