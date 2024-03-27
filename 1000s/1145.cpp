#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    vector <int> arr(5);
    for(int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    int min_num = INT32_MAX;
    for(int i = 0; i < 3; i++)
    {
        for(int j = i+1; j < 4; j++)
        {
            for(int k = j+1; k < 5; k++)
            {
                min_num = min(min_num, lcm(lcm(arr[i], arr[j]), arr[k]));
            }
        }
    }

    cout << min_num;
}