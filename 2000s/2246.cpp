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

    int count = 0;
    for(int i = 0; i < n; i++)
    {
        bool flag = true;
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            {
                continue;
            }
            
            if(arr[i].first > arr[j].first)
            {
                if(arr[i].second >= arr[j].second)
                {
                    flag = false;
                    break;
                }
            }
            
            if(arr[i].second > arr[j].second)
            {
                if(arr[i].first >= arr[j].first)
                {
                    flag = false;
                    break;
                }
            }
        }

        if(flag)
        {
            count++;
        }
    }

    cout << count;
}