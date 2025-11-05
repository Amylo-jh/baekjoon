#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, k, answer = 0, sum = 0, lo = 0, hi = -1;
    cin >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    for(lo = 0; lo < n; lo++)
    {
        while(hi < n && sum <= k)
        {
            hi++;
            sum += arr[hi];
        }
        answer += n - hi;
        sum -= arr[lo];
    }
    cout << answer;
}