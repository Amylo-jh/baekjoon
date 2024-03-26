#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector <int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int count = 0;
    int idx[2] = {0, n-1};
    while(idx[0] < idx[1])
    {
        if(arr[idx[0]] + arr[idx[1]] == m)
        {
            count++;
            idx[0]++;
            idx[1]--;
        }
        else if(arr[idx[0]] + arr[idx[1]] < m)
        {
            idx[0]++;
        }
        else
        {
            idx[1]--;
        }
    }

    cout << count;
}