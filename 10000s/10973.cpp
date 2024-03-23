#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> arr(n);
    vector <int> arr2(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    arr2 = arr;
    sort(arr2.begin(), arr2.end());
    if(arr == arr2)
    {
        cout << -1;
        return 0;
    }
    
    prev_permutation(arr.begin(), arr.end());

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }   
}