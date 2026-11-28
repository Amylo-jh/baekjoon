#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<int> arr(5);
        for (int i = 0; i < 5; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        if (arr[3] - arr[1] >= 4)
        {
            cout << "KIN\n";
        }
        else
        {
            cout << arr[1] + arr[2] + arr[3] << "\n";
        }
    }
}