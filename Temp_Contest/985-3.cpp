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
    sort(arr.begin(), arr.end(), greater<>());

    int total_level = 0;
    int total_ability = 0;
    for(int i = 0; i < min(n, 42); i++)
    {
        if(arr[i] >= 60)
        {
            total_ability++;
        }
        if(arr[i] >= 100)
        {
            total_ability++;
        }
        if(arr[i] >= 140)
        {
            total_ability++;
        }
        if(arr[i] >= 200)
        {
            total_ability++;
        }
        if(arr[i] >= 250)
        {
            total_ability++;
        }

        total_level += arr[i];
    }

    cout << total_level << " " << total_ability;
}