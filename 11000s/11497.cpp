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
        int n;
        cin >> n;
        vector <int> arr(n);
        vector <int> newarr(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());

        int i = 0, j = n-1;
        for(int k = 0; k < n; k++)
        {
            if(k % 2 == 0)
            {
                newarr[i] = arr[k];
                i++;
            }
            else
            {
                newarr[j] = arr[k];
                j--;
            }
        }

        int max_diff = 0;
        for(int i = 0; i < n-1; i++)
        {
            max_diff = max(max_diff, abs(newarr[i] - newarr[i+1]));
        }
        max_diff = max(max_diff, abs(newarr[n-1] - newarr[0]));

        cout << max_diff << "\n";
    }
}