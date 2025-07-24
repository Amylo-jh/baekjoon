#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <pair <int, int>> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());
    int count = 1;
    for(int i = 1; i < n; i++)
    {
        if(arr[i].first > arr[i-1].first + arr[i-1].second)
        {
            count++;
        }
    }
    cout << count;
}