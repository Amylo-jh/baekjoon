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
    
    vector <int> dp(n+1);
    dp.assign(n+1, INT32_MAX);
    dp[0] = 0;
    dp[1] = 0;

    for(int i = 1; i <= n; i++)
    {
        if(i % 3 == 0)
        {
            dp[i] = min(dp[i], dp[i/3]+1);
        }
        if(i % 2 == 0)
        {
            dp[i] = min(dp[i], dp[i/2]+1);
        }
        dp[i] = min(dp[i], dp[i-1]+1);
    }

    vector <int> path;
    path.push_back(n);
    int count = dp[n];
    int curr_num = n;
    while(count)
    {
        if(curr_num % 3 == 0 && dp[curr_num/3] == count-1)
        {
            path.push_back(curr_num/3);
            count--;
            curr_num /= 3;
            continue;
        }

        if(curr_num % 2 == 0 && dp[curr_num/2] == count-1)
        {
            path.push_back(curr_num/2);
            count--;
            curr_num /= 2;
            continue;
        }

        if(dp[curr_num-1] == count-1)
        {
            path.push_back(curr_num-1);
            count--;
            curr_num--;
            continue;
        }
    }

    cout << dp[n] << "\n";
    for(int i : path)
    {
        cout << i << " ";
    }
}