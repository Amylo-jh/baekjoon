#include <iostream>

using namespace std;

int main()
{
    int min_val = INT32_MAX;
    int sum = 0;

    for(int i = 0; i < 7; i++)
    {
        int temp;
        cin >> temp;
        if(temp % 2)
        {
            min_val = min(min_val, temp);
            sum += temp;
        }
    }

    if(sum == 0)
    {
        cout << -1;
    }
    else
    {
        cout << sum << "\n" << min_val;
    }
}