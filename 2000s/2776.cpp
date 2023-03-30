#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tc;
    cin >> tc;

    while(tc--)
    {
        int n, m;
        cin >> n;
        vector <int> arr1(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        cin >> m;
        vector <int> arr2(m);
        for(int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        sort(arr1.begin(), arr1.end());

        for(int i = 0; i < m; i++)
        {
            int pos = lower_bound(arr1.begin(), arr1.end(), arr2[i]) - arr1.begin();
            if(arr1[pos] == arr2[i])
            {
                cout << "1\n";
            }
            else
            {
                cout << "0\n";
            }
        }
    }
}