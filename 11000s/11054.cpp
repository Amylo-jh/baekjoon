#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    vector <int> dp1;
    vector <int> dp2;
    dp1.assign(n, 1);
    dp2.assign(n, 1);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[j] < arr[i] && dp1[i] < dp1[j]+1)
            {
                dp1[i] = dp1[j]+1;
            }
        }
    }
     
    for(int i = n-2; i >= 0; i--)
    {
        for(int j = n-1; j > i; j--)
        {
            if(arr[j] < arr[i] && dp2[i] < dp2[j]+1)
            {
                dp2[i] = dp2[j]+1;
            }
        }
    }

    int max_value = 0;
    for(int i = 0; i < n; i++)
    {
        dp1[i] += dp2[i];
        max_value = max(max_value, dp1[i]);
    }

    cout << max_value -1;
}