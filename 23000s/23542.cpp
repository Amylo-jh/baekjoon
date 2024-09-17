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

    vector <int> arr(n*2);
    for(int i = 0; i < n*2; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    vector <int> sum(n);
    for(int i = 0; i < n; i++)
    {
        sum[i] = arr[i] + arr[2*n-1-i];
    }
    sort(sum.begin(), sum.end());

    cout << sum[n-1] - sum[0];
}