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

    long long m;
    cin >> m;
    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] <= m)
        {
            sum += arr[i]*arr[i];
            m -= arr[i];
        }
        else
        {
            sum += m*m;
            break;
        }
    }
    cout << sum;
}