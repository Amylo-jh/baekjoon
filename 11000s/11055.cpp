#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int max_sum = 0;
    vector <int> arr(n);
    vector <int> dp_sum(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    dp_sum = arr;

    for(int i = 0; i < n; i++)
    {
        int temp_sum = arr[i];

        for(int j = 0; j < i; j++)
        {
            if(arr[j] < arr[i])
            {
                temp_sum = max(temp_sum, dp_sum[j] + arr[i]);
            }
        }

        dp_sum[i] = temp_sum;
        max_sum = max(max_sum, temp_sum);
    }

    cout << max_sum;
}