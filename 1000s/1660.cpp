#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> arr;
    vector <int> dp(300001, INT32_MAX);

    int num = 1;
    int ball = 1;
    int sum = 1;
    while(ball <= 300000)
    {
        arr.push_back(sum);
        num++;
        ball += num;
        sum += ball;
    }

    dp[0] = 0;
    for(int i = 0; i <= 300000; i++)
    {
        for(int j = 0; j < arr.size(); j++)
        {
            if(i + arr[j] <= 300000)
            {
                dp[i + arr[j]] = min(dp[i + arr[j]], dp[i] + 1);
            }
            else
            {
                break;
            }
        }
    }

    cout << dp[n];
}