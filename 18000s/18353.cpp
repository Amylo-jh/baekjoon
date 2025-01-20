#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> arr(n);
    vector <int> lcs;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    reverse(arr.begin(), arr.end());

    for(int i = 0; i < n; i++)
    {
        auto pos = lower_bound(lcs.begin(), lcs.end(), arr[i]);
        if(pos == lcs.end())
        {
            lcs.push_back(arr[i]);
        }
        else
        {
            *pos = arr[i];
        }
    }

    cout << n - lcs.size();
}