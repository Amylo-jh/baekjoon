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

    vector <int> price(n);
    for(int i = 0; i < n; i++)
    {
        cin >> price[i];
    }

    int min_price = INT32_MAX;
    int max_profit = 0;
    for(int i = 0; i < n; i++)
    {
        min_price = min(min_price, price[i]);
        max_profit = max(max_profit, price[i] - min_price);
    }

    cout << max_profit;
}