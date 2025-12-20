#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        int n, max_diff = 0;
        cin >> n;
        vector <int> arr(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        for(int i = 1; i < n; i++)
        {
            max_diff = max(max_diff, arr[i] - arr[i-1]);
        }
        
        cout << "Class " << tc << "\n";
        cout << "Max " << arr[n-1] << ", Min " << arr[0] << ", Largest gap " << max_diff << "\n";
    }
}