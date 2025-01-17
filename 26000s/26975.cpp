#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <long long> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<>());

    long long sum = 0;
    long long value = 0;
    for(int i = 0; i < n; i++)
    {
        if(sum <= arr[i]*(i+1))
        {
            sum = arr[i]*(i+1);
            value = arr[i];
        }
    }
    cout << sum << " " << value;
}