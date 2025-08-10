#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <long long> arr(n);
    long long sum = 0;
    long long sq_sum = 0;
    long long max_value = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    for(int i = 0; i < n; i++)
    {
        sq_sum += arr[i]*arr[i];
        sum -= arr[i];
        max_value = max(max_value, sum * sq_sum);
    }
    cout << max_value;
}