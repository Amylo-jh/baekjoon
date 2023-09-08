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
    sort(arr.begin(), arr.end());
    
    int max_pos = 0;
    for(int i = n-1; i >= 0; i--)
    {
        int sum = arr[i];
        for(int j = i; j >= 0; j--)
        {
            for(int k = j; k >= 0; k--)
            {
                if(arr[j] + arr[k] > sum)
                {
                    continue;
                }

                for(int l = k; l >= 0; l--)
                {
                    if(arr[j] + arr[k] + arr[l] == sum)
                    {
                        cout << sum;
                        i = j = k = l = -1;
                    }
                }
            }
        }
    }
}