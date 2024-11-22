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
        vector <long long> arr(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());

        int count = 0;
        for(int i = 0; i < n-1; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                long long mid =(arr[i] + arr[j])/2;
                if(mid*2 != arr[i] + arr[j])
                {
                    continue;
                }
                
                if(binary_search(arr.begin(), arr.end(), mid))
                {
                    count++;
                }
            }
        }

        cout << count << "\n";
    }
}