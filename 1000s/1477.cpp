#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, l;
    cin >> n >> m >> l;
    vector <int> rest(n+2);
    vector <int> diff(n+1);
    for(int i = 0; i < n; i++)
    {
        cin >> rest[i];
    }
    rest[n] = 0;
    rest[n+1] = l;
    sort(rest.begin(), rest.end());
    for(int i = 0; i < n+1; i++)
    {
        diff[i] = rest[i+1] - rest[i]-1;
    }
    sort(diff.begin(), diff.end());

    int lo = 1;
    int hi = l-1;
    int result = hi;

    while(lo <= hi)
    {
        int count = 0;
        int mid = (lo+hi)/2;

        for(int i = 0; i <= n; i++)
        {
            count += diff[i] / mid;          
        }

        if(count > m)
        {
            lo = mid+1;
        }
        else
        {
            result = min(result, mid);
            hi = mid-1;
        }
    }

    cout << result;
}