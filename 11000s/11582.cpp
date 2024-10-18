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

    int unit;
    cin >> unit;

    for(int i = 0; i < n; i = i + n/unit)
    {
        sort(arr.begin()+i, arr.begin()+i+n/unit);
    }

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}