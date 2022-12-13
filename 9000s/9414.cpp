#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        vector <int> price;
        int value = 1;
        
        while(value)
        {
            cin >> value;
            if(value)
            {
                price.push_back(value);
            }
        }
        sort(price.begin(), price.end(), greater<>());
        
        int total_price = 0;
        int multiplier = 1;
        for(int i = 0; i < price.size(); i++)
        {
            total_price += pow(price[i], i+1);
        }

        if(total_price > 2500000)
        {
            cout << "Too expensive\n";
        }
        else
        {
            cout << total_price * 2 << "\n";
        }
    }
}