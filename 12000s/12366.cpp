#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
    {
        int n;
        cin >> n;
        vector <pair <pair <int, int>, int>> arr(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i].first.second;
            arr[i].first.second *= -1;
        }
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i].first.first;
            arr[i].first.first *= -1;
            arr[i].second = i;
        }
        sort(arr.begin(), arr.end());
        
        cout << "Case #" << tc << ": ";
        for(auto i : arr)
        {
            cout << i.second << " ";
        }
        cout << "\n";
    }
}