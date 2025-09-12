#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x, y;
    cin >> n >> x >> y;
    vector <int> arr(n);
    vector <int> target(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i] >> target[i];
    }
    sort(arr.begin(), arr.end());
    sort(target.begin(), target.end());
    long long sum = 0, diff;
    for(int i = 0; i < n; i++)
    {
        diff = target[i] - arr[i];
        if(diff > 0)
        {
            sum += diff*x;
        }
        else
        {
            sum += -diff*y;
        }
    }
    cout << sum;
}