#include <iostream>
#include <vector>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) < (b)) ? (b) : (a))

using namespace std;

int main()
{
    vector <int> coins = {0};
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        int curr_coin = coins[i-1] + 1;

        if(i - 2 >= 0)
        {
            curr_coin = min(curr_coin, coins[i-2] + 1);
        }
        if(i - 5 >= 0)
        {
            curr_coin = min(curr_coin, coins[i-5] + 1);
        }
        if(i - 7 >= 0)
        {
            curr_coin = min(curr_coin, coins[i-7] + 1);
        }
        
        coins.push_back(curr_coin);
    }

    cout << coins[n];
}