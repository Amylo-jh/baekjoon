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

    while(1)
    {
        vector <int> dp;
        dp.reserve(250000);
        int max_income = -10000;
        int day = 1;
        cin >> day;

        if(day == 0)
        {
            break;
        }

        for(int i = 0; i < day; i++)
        {
            int temp;
            cin >> temp;

            dp.push_back(temp);

            if(i > 0)
            {
                dp[i] = max(dp[i-1] + temp, temp);
            }

            max_income = max(max_income, dp[i]);
        }

        cout << max_income << "\n";
    }
}