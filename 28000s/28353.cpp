#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, lo, hi;
    cin >> n >> k;
    vector <int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<>());
    lo = 0, hi = n-1;
    int cat = 0;
    while(lo < hi)
    {
        if(arr[lo] + arr[hi] <= k)
        {
            cat++;
            lo++;
            hi--;
        }
        else
        {
            lo++;
        }
    }
    cout << cat;
}