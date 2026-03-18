#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, first = 0;
    cin >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    first = arr[0];
    sort(arr.begin(), arr.end());
    if(first == arr[0])
    {
        cout << "ez";
    }
    else if(first == arr[n-1])
    {
        cout << "hard";
    }
    else
    {
        cout << "?";
    }
}