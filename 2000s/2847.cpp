#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> cost(n);
    for(int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }

    int count = 0;
    for(int i = n-1; i > 0; i--)
    {
        if(cost[i] <= cost[i-1])
        {
            count += cost[i-1] - cost[i] + 1;
            cost[i-1] = cost[i] - 1;
        }
    }

    cout << count << '\n';
}