#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector <int> liquid(n);

    for(int i = 0; i < n; i++)
    {
        cin >> liquid[i];
    }

    sort(liquid.begin(), liquid.end());

    int lo = 0;
    int hi = n-1;
    long long min_sum = INT64_MAX;
    pair <int, int> status;

    while(lo < hi)
    {
        long long sum;
        sum = liquid[lo] + liquid[hi];

        if(abs(sum) < abs(min_sum))
        {
            min_sum = sum;
            status.first = liquid[lo];
            status.second = liquid[hi];
        }

        if(sum > 0)
        {
            hi--;
        }
        else if(sum < 0)
        {
            lo++;
        }
        else if(sum == 0)
        {
            min_sum = sum;
            status.first = liquid[lo];
            status.second = liquid[hi];
            break;
        }
    }

    cout << status.first << " " << status.second;
}