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
    vector <int> lis;

    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    lis.push_back(arr[1]);

    int cnt = 0;
    for(int i = 2; i <= n; i++)
    {
        if(lis[cnt] < arr[i])
        {
            lis.push_back(arr[i]);
            cnt++;
        }
        else
        {
            int pos = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
            lis[pos] = arr[i];

        }
    }

    cout << lis.size();
}