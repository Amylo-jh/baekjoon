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
    vector <int> arr(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] += i-1;
        if(arr[i-1] >= arr[i])
        {
            arr[i] = arr[i-1];
        }
    }
    cin >> n;
    int num, idx;
    for(int i = 0; i < n; i++)
    {
        cin >> num;
        idx = lower_bound(arr.begin(), arr.end(), num) - arr.begin();
        cout << idx << ' ';
    }
}