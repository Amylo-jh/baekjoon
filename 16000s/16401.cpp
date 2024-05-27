#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    cin >> m >> n;

    int hi = 0;
    int lo = 1;
    vector <int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        hi = max(hi, arr[i]);
    }

    int result = 0;
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        int sum = 0;

        if(mid == 0)
        {
            result = 0;
            break;
        }

        for(int i = 0; i < n; i++)
        {
            sum += arr[i] / mid;
        }

        if(sum >= m)
        {
            lo = mid + 1;
            result = mid;
        }
        else
        {
            hi = mid - 1;
        }
    }

    cout << result;
}