#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc;
    cin >> tc;
    
    long long total = 0;
    vector <pair <int, int>> answer;
    while(tc--)
    {
        int n;
        cin >> n;
        vector <long long> arr(n+1);
        vector <long long> sum(n+1);
        for(int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            sum[i] = sum[i-1] + arr[i];
        }

        pair <int, int> ans = {0, 0};
        long long max_value = LONG_LONG_MIN;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= n-i; j++)
            {
                long long temp = sum[j+i] - sum[j];

                if(temp > max_value)
                {
                    max_value = temp;
                    ans = {j+1, j+i};
                }
            }
        }

        total += max_value;
        answer.push_back(ans);
    }

    cout << total << "\n";
    for(auto p : answer)
    {
        cout << p.first << " " << p.second << "\n";
    }
}