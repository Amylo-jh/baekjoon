#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, c;
    cin >> n >> c;

    vector <int> house(n);
    for(int i = 0; i < n; i++)
    {
        cin >> house[i];
    }
    sort(house.begin(), house.end());

    int hi = house[n-1] - house[0];
    int lo = 1;
    int result = 0;
    while(lo <= hi)
    {
        int mid = (hi + lo) / 2;
        int count = 1;
        int flag_house = 0;

        for(int i = 1; i < n; i++)
        {
            if(house[i] - house[flag_house] >= mid)
            {
                count++;
                flag_house = i;
            }
        }

        if(count >= c)
        {
            result = max(result, mid);
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    cout << result;
}