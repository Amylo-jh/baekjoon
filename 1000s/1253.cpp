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
    vector <long long> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int count = 0;
    for(int i = 0; i < n; i++)
    {
        int lo = 0, hi = n-1;
        while(lo < hi)
        {
            if(arr[lo] + arr[hi] == arr[i])
            {
                if(lo != i && hi != i)
                {
                    count++;
                    break;
                }
                else
                {
                    if(lo == i)
                    {
                        lo++;
                    }
                    if(hi == i)
                    {
                        hi--;
                    }
                }
            }
            else
            {
                if(arr[lo] + arr[hi] > arr[i])
                {
                    hi--;
                }
                else if(arr[lo] + arr[hi] < arr[i])
                {
                    lo++;
                }
            }
        }
    }

    cout << count;
}