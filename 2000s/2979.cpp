#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> cost(4);
    vector <int> arr(101);
    for(int i = 1; i <= 3; i++)
    {
        cin >> cost[i];
    }
    for(int i = 0; i < 3; i++)
    {
        int a, b;
        cin >> a >> b;
        for(int j = a; j < b; j++)
        {
            arr[j]++;
        }
    }

    int sum = 0;
    for(int i = 1; i <= 100; i++)
    {
        sum += arr[i] * cost[arr[i]];
    }

    cout << sum << '\n';
}