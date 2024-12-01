#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        vector <int> price(n);
        for(int i = 0; i < n; i++)
        {
            cin >> price[i];
        }

        int maxprice = price[n-1];
        long long profit = 0;
        for(int i = n-1; i >= 0; i--)
        {
            maxprice = max(maxprice, price[i]);
            profit += maxprice - price[i];
        }

        cout << profit << "\n";
    }
}