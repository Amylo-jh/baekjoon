#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    while (1)
    {
        vector<int> arr(6);
        int sum = 0;
        for (int i = 0; i < 6; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        if (sum == 0)
        {
            break;
        }
        sort(arr.begin(), arr.end());
        sum -= arr[0] + arr[5];
        cout << double(sum) / 4 << "\n";
    }
}