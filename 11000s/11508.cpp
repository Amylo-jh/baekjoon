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
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<>());

    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        if((i+1) % 3)
        {
            sum += arr[i];
        }
    }

    cout << sum;
}