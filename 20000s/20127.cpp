#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector <int> arr(n);
    vector <int> diff(n-1);

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int minus = 0;
    int plus = 0;
    int zero = 0;
    for(int i = 0; i < n-1; i++)
    {
        diff[i] = arr[i+1] - arr[i];
        if(diff[i] < 0)
        {
            minus++;
        }
        else if(diff[i] > 0)
        {
            plus++;
        }
        else
        {
            zero++;
        }
    }

    if(minus == 0 || plus == 0 || zero == n-1)
    {
        cout << 0;
        return 0;
    }

    minus += zero;
    plus += zero;


    int answer = INT32_MAX;
    if(plus == n-2) // 증가하는 수열
    {
        if(arr[0] < arr[n-1])
        {
            
        }
        else
        {
            for(int i = 0; i < n-1; i++)
            {
                if(diff[i] < 0)
                {
                    answer = min(answer, i+1);
                    // cout << i+1;
                }
            }
        }
    }
    
    if(minus == n-2) // 감소하는 수열
    {
        if(arr[0] > arr[n-1])
        {
            
        }
        else
        {
            for(int i = 0; i < n-1; i++)
            {
                if(diff[i] > 0)
                {
                    answer = min(answer, i+1);
                    // cout << i+1;
                }
            }
        }
    }

    if(answer == INT32_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << answer;
    }
}