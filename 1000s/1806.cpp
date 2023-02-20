#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;
    
    vector <int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int low = 0;
    int hi = 0;
    int sum = arr[0];
    int len = INT32_MAX;
    
    while(low <= hi && hi < n)
    {
        if(sum < s)
        {
            hi++;
            sum += arr[hi];
        }
        else
        {
            len = min(len, hi - low + 1);
            sum -= arr[low];
            low++;
        }
    }

    if(len == INT32_MAX)
    {
        cout << 0;
    }
    else
    {
        cout << len;
    }
}