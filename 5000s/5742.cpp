#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    while(1)
    {
        int n, c, k, tmp;
        cin >> n >> c >> k;
        if(n == 0 && c == 0 && k == 0)
        {
            break;
        }
        vector <pair <int, int>> arr(k+1);
        arr[0].first = 100000;
        for(int i = 1; i <= k; i++)
        {
            arr[i].second = i;
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < c; j++)
            {
                cin >> tmp;
                arr[tmp].first++;
            }
        }
        sort(arr.begin(), arr.end());
        tmp = 0;
        cout << arr[tmp].second;
        while(tmp < k && arr[tmp].first == arr[tmp+1].first)
        {
            cout << " " << arr[tmp+1].second;
            tmp++;
        }
        cout << "\n";
    }
}