#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    vector <int> lis;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    lis.push_back(arr[n-1]);
    int index = 0;

    for(int i = n-2; i >= 0; i--)
    {
        if(lis[index] < arr[i])
        {
            lis.push_back(arr[i]);
            index++;
        }
        else
        {
            int target_index = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
            lis[target_index] = arr[i];
        }
    }

    cout << index+1;
}