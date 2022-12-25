#include <iostream>

using namespace std;

int main()
{
    int sum = 0;
    int max_v = 0;
    int min_v = INT32_MAX;
    for(int i = 0; i < 3; i++)
    {
        int temp;
        cin >> temp;
        sum += temp;
        max_v = max(max_v, temp);
        min_v = min(min_v, temp);
    }

    cout << sum - max_v - min_v;
}