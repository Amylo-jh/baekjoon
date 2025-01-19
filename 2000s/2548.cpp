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

    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr.begin(), arr.end());

    int answer = arr[0];
    int min_diff = sum - arr[0]*n;

    for(int i = 1; i < n; i++)
    {
        int diff = arr[i] - arr[i-1];
        int next_diff = min_diff - (n-i) * diff + (diff*i);
        if(next_diff < min_diff)
        {
            answer = arr[i];
            min_diff = next_diff;
        }
    }

    cout << answer;
}