#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector <int> arr(n*2);
    for(int i = 0; i < n; i++)
    {
        int t, temp;
        cin >> t >> temp;
        arr[i*2] = temp;
        for(int j = 1; j < t; j++)
        {
            cin >> temp;
        }
        arr[i*2+1] = temp;
    }

    sort(arr.begin(), arr.end());
    cout << arr[n-1];
}