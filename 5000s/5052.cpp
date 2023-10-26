#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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
        vector <string> arr(n);

        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        
        bool flag = false;
        for(int i = 0; i < n-1; i++)
        {
            if(arr[i].length() == arr[i+1].length())
            {
                continue;
            }
            else
            {
                if(arr[i+1].substr(0, arr[i].size()) == arr[i])
                {
                    flag = true;
                    break;
                }
            }
        }

        if(flag)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
}