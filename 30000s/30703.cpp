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

    bool is_odd = true;
    long long answer = -1;

    vector <long long> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;
        arr[i] = abs(arr[i] - temp);
    }
    for(int i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;

        if(arr[i] == 0)
        {
            arr[i] = 0;
        }
        else if(arr[i] % temp == 0)
        {
            arr[i] = arr[i] / temp;
        }
        else
        {
            cout << -1;
            return 0;
        }
    }

    if(arr[0] % 2 == 0)
    {
        is_odd = false;
    }
    for(int i = 0; i < n; i++)
    {   
        if(is_odd)
        {
            if(arr[i] % 2 == 0)
            {
                answer = -1;
                break;
            }
        }
        else
        {
            if(arr[i] % 2 == 1)
            {
                answer = -1;
                break;
            }
        }
        answer = max(answer, arr[i]);
    }

    cout << answer;
}