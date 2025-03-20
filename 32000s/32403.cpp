#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    vector <int> arr(n);
    vector <int> divisor;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for(int i = 1; i <= t; i++)
    {
        if(t % i == 0)
        {
            divisor.push_back(i);
        }
    }

    int answer = 0;
    for(int i = 0; i < n; i++)
    {
        int min_diff = 10000;
        for(int j = 0; j < divisor.size(); j++)
        {
            int diff = abs(arr[i] - divisor[j]);
            if(diff < min_diff)
            {
                min_diff = diff;
            }
            else
            {
                break;
            }
        }
        answer += min_diff;
    }

    cout << answer;
}