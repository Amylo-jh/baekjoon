#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, min_value = INT32_MAX, idx = 0;
    cin >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(arr[i] < min_value)
        {
            min_value = arr[i];
            idx = i;
        }
    }
    cout << idx;
}