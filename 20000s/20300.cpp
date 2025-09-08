#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, max_value = 0;
    cin >> n;
    vector <long long> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    if(n % 2)
    {
        for(int i = 0; i < n-1; i++)
        {
            max_value = max(max_value, arr[i] + arr[n-i-2]);
        }
        max_value = max(max_value, arr[n-1]);
    }
    else
    {
        for(int i = 0; i < n/2; i++)
        {
            max_value = max(max_value, arr[i] + arr[n-i-1]);
        }
    }
    cout << max_value;
}