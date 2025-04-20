#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int answer = 0;
    for(int i = 0; i < n; i++)
    {
        int left_max = 0;
        int right_max = 0;
        for(int j = 0; j < i; j++)
        {
            left_max = max(left_max, arr[j]);
        }
        for(int j = i+1; j < n; j++)
        {
            right_max = max(right_max, arr[j]);
        }
        answer += max(0, min(left_max, right_max) - arr[i]);
    }

    cout << answer;
}