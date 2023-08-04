#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector <int> arr(n*n);
    for(int i = 0; i < n*n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    cout << arr[n*n-n];
}