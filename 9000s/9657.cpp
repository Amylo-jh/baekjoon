#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <bool> dp(n+1);
    
    // if True, SK wins.
    // else, CY wins.
    dp[1] = true;
    dp[2] = false;
    dp[3] = true;
    dp[4] = true;

    for(int i = 5; i <= n; i++)
    {
        if(dp[i-1] == false || dp[i-3] == false || dp[i-4] == false)
        {
            dp[i] = true;
        }
        else
        {
            dp[i] = false;
        }
    }

    if(dp[n] == true)
    {
        cout << "SK";
    }
    else
    {
        cout << "CY";
    }
}