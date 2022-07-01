#include <iostream>
#include <vector>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) < (b)) ? (b) : (a))

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector <int> dp;
    dp.reserve(n);
    int max_sum = -9999;

    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        
        dp.push_back(num);
        
        if(i > 0)
        {
            dp[i] = max(dp[i-1] + num, num);
        }

        max_sum = max(max_sum, dp[i]);
    }

    cout << max_sum;
}