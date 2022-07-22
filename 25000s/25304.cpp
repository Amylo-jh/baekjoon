#include <iostream>

using namespace std;

int main()
{
    int total_cost;
    int n;

    cin >> total_cost >> n;

    int cost_sum = 0;
    for(int i = 0; i < n; i++)
    {
        int cost, count;
        cin >> cost >> count;
        cost_sum += cost * count;
    }

    if(total_cost != cost_sum)
    {
        cout << "No";
    }
    else
    {
        cout << "Yes";
    }
}