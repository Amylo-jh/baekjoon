#include <iostream>

using namespace std;

int main()
{
    int n, value = 99;
    cin >> n;
    int max_diff = abs(n - value);
    while (1)
    {
        if (abs(n - (value + 100)) <= max_diff)
        {
            value += 100;
            max_diff = abs(n - value);
        }
        else
        {
            break;
        }
    }
    cout << value;
}