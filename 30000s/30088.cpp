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
        int people;
        cin >> people;

        for(int j = 0; j < people; j++)
        {
            int temp;
            cin >> temp;
            arr[i] += temp;
        }
    }

    sort(arr.begin(), arr.end());
    for(int i = 1; i < n; i++)
    {
        arr[i] += arr[i-1];
    }
    
    long long total_time = 0;
    for(int i = 0; i < n; i++)
    {
        total_time += arr[i];
    }

    cout << total_time;
}
