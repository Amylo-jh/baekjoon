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

    long long count = 0;
    int minus = 1;
    for(int i = 0; i < n; i++)
    {
        int curr_count = arr[i] - minus;
        if(curr_count < 0)
        {
            continue;
        }

        count += curr_count;
        minus++;
    }

    cout << count;
}