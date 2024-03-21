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
    int result = 0;

    do
    {
        int sum = 0;
        for(int i = 0; i < n-1; i++)
        {
            sum += abs(arr[i] - arr[i+1]);
        }
        result = max(sum, result);
    }
    while(next_permutation(arr.begin(), arr.end()));

    cout << result << endl;
}