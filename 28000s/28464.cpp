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
    
    int small = 0;
    int big = 0;
    
    for(int i = 0; i < n/2; i++)
    {
        small += arr[i];
    }
    for(int i = n/2; i < n; i++)
    {
        big += arr[i];
    }
    
    cout << small << " " << big;
}