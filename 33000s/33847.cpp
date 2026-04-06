#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, c, max_profit = 0, max_food = 0;
    cin >> n >> c;
    // input : eat, size, price
    // saved : size, eat, price, used
    vector<vector<int>> fish(n, vector<int>(4));
    for (int i = 0; i < n; i++)
    {
        cin >> fish[i][1] >> fish[i][0] >> fish[i][2];
        max_food += fish[i][1];
    }
    sort(fish.begin(), fish.end(), greater<>());

    for (int i = 1; i <= max_food; i++)
    {
        int curr_food = i;
        int curr_profit = -i * c;
        while (curr_food)
        {
            bool not_ate = true;
            for (int j = 0; j < n; j++)
            {
                if (!fish[j][3] && fish[j][1] <= curr_food)
                {
                    fish[j][3] = 1;
                    curr_profit += fish[j][2];
                    curr_food -= fish[j][1];
                    not_ate = false;
                }
            }
            if (not_ate || !curr_food)
            {
                max_profit = max(max_profit, curr_profit);
                break;
            }
        }
        // reset used;
        for (int j = 0; j < n; j++)
        {
            fish[j][3] = 0;
        }
    }
    cout << max_profit;
}