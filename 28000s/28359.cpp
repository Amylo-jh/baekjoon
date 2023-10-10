#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int max_value = 0;
    int sum = 0;
    cin >> n;
    vector <int> num(1001);
    vector <int> arr(n);
    
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        num[temp] += temp;
        arr[i] = temp;
        sum += temp;
    }
    for(int i = 1; i <= 1000; i++)
    {
        max_value = max(max_value, num[i]);
    }
    sort(arr.begin(), arr.end());
    sum += max_value;

    cout << sum << "\n";
    for(auto i : arr)
    {
        cout << i << " ";
    }
}