#include <iostream>
#include <vector>

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
        int n, tmp, mn, mx;
        cin >> n;
        vector <int> arr(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        arr[0] = min(arr[0], n-arr[0]+1);
        bool flag = true;
        for(int i = 1; i < n; i++)
        {
            mn = min(arr[i], n-arr[i]+1);
            mx = max(arr[i], n-arr[i]+1);
            if(arr[i-1] <= mn)
            {
                arr[i] = mn;
            }
            else if(arr[i-1] <= mx)
            {
                arr[i] = mx;
            }
            else
            {
                cout << "NO\n";
                flag = false;
                break;
            }
        }
        if(flag)
        {
            cout << "YES\n";
        }
    }
}