#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <long long> arr(n);
    long long sum = 0;
    long long answer = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    for(int i = 0; i < n-1; i++)
    {
        sum -= arr[i];
        answer += arr[i] * sum;
    }
    cout << answer;
}