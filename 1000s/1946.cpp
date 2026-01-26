#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        vector <pair <int, int>> arr(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i].first >> arr[i].second;
        }
        sort(arr.begin(), arr.end());
        int count = 0, max_rank = arr[0].second;
        for(int i = 0; i < n; i++)
        {
            if(arr[i].second <= max_rank)
            {
                count++;
                max_rank = arr[i].second;
            }
        }
        cout << count << "\n";
    }
}