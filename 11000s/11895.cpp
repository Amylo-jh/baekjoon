#include <iostream>

using namespace std;

int main()
{
    int n, sum = 0, tmp, x = 0, min_value = INT32_MAX;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        x ^= tmp;
        sum += tmp;
        min_value = min(min_value, tmp);
    }
    if (x != 0)
    {
        cout << 0;
    }
    else
    {
        cout << sum - min_value;
    }
}