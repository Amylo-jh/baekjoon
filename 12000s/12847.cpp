#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector <long long> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long sum = 0;
    long long max_value = 0;
    for(int i = 0; i < m; i++)
    {
        sum += arr[i];
    }
    max_value = sum;
    for(int i = m; i < n; i++)
    {
        sum += arr[i] - arr[i - m];
        max_value = max(max_value, sum);
    }
    cout << max_value;
}