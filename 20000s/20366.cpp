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
    vector <int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int min_diff = INT32_MAX;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            int sum1 = arr[i]+arr[j];
            int a = 0, b = n-1;
            while(a < b)
            {
                if(a == i || a == j)
                {
                    a++;
                    continue;
                }
                if(b == i || b == j)
                {
                    b--;
                    continue;
                }
                int sum2 = arr[a]+arr[b];
                int diff = abs(sum1-sum2);
                min_diff = min(diff, min_diff);

                if(sum1 > sum2)
                {
                    a++;
                    continue;
                }
                if(sum1 < sum2)
                {
                    b--;
                    continue;
                }
                if(sum1 == sum2)
                {
                    break;
                }
            }
        }
    }

    cout << min_diff;
}