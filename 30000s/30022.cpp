#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, a, b;
    cin >> n >> a >> b;

    long long sum = 0;

    vector <long long> arr1(n);
    vector <long long> arr2(n);
    priority_queue <pair <long long, int>> pq;

    for(int i = 0; i < n; i++)
    {
        cin >> arr1[i] >> arr2[i];
        pq.push({abs(arr1[i] - arr2[i]), i});
    }

    while(!pq.empty())
    {
        int i = pq.top().second;
        if(arr1[i] > arr2[i])
        {
            if(b > 0)
            {
                sum += arr2[i];
                b--;
            }
            else
            {
                sum += arr1[i];
                a--;
            }
        }
        else if(arr1[i] < arr2[i])
        {
            if(a > 0)
            {
                sum += arr1[i];
                a--;
            }
            else
            {
                sum += arr2[i];
                b--;
            }
        }
        else
        {
            sum += arr1[i];
        }

        pq.pop();
    }

    cout << sum;
}