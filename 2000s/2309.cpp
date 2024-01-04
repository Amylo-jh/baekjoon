#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector <int> arr(9);
    int sum = 0;
    for(int i = 0; i < 9; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr.begin(), arr.end());

    for(int i = 0; i < 8; i++)
    {
        for(int j = i+1; j < 9; j++)
        {
            if(sum - arr[i] - arr[j] == 100)
            {
                for(int k = 0; k < 9; k++)
                {
                    if(k == i || k == j)
                    {
                        continue;
                    }
                    cout << arr[k] << "\n";
                }
                i = 9;
                j = 9;
                break;
            }
        }
    }
}