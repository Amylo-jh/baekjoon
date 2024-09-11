#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector <long long> arr(n+1);
    vector <long long> sum(n+1);

    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
    }

    int answer = 0;
    for(int interval = 1; interval <= n; interval++)
    {
        for(int j = 1; j <= n-interval+1; j++)
        {
            if(sum[j+interval-1] - sum[j-1] == m)
            {
                answer++;
            }
        }
    }

    cout << answer;
}