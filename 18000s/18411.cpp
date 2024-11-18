#include <iostream>

using namespace std;

int main()
{
    int sum = 0, min_value = INT32_MAX;
    for(int i = 0; i < 3; i++)
    {
        int temp;
        cin >> temp;
        sum += temp;
        min_value = min(temp, min_value);
    }

    cout << sum - min_value;
}