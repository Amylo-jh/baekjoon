#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    vector <pair <int, int>> arr2;
    arr2.push_back({arr[0], 1});
    int index = 0;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] == arr2[index].first)
        {
            arr2[index].second++;
        }
        else
        {
            arr2.push_back({arr[i], 1});
            index++;
        }
    }

    int max_value = 0;
    for(int i = 0; i < arr2.size(); i++)
    {
        max_value = max(max_value, arr2[i].second);
    }

    if(max_value > (n-1)/2+1)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }
}