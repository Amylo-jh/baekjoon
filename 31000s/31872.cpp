#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector <int> arr(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++)
    {
        arr[i] = arr[i+1] - arr[i];
    }
    arr[n] = 0;
    sort(arr.begin(), arr.end(), greater<>());
    
    long long total_time = 0;
    for(int i = k; i < n; i++)
    {
        total_time += arr[i];
    }
    cout << total_time;
}