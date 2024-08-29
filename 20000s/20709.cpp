#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    int min_money = INT32_MAX;
    int idx = 0;

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        vector <int> year = {1, 1, 2};
        int money;
        string str;
        
        cin >> money >> str;

        for(int j = 0; j < str.length(); j++)
        {
            if(str[j] == '0')
            {
                year[0] = max(0, year[0] - 1);
            }
            else if(str[j] == '1')
            {
                year[1] = max(0, year[1] - 1);
            }
            else if(str[j] == '2')
            {
                year[2] = max(0, year[2] - 1);
            }
        }

        if(year[0] == 0 && year[1] == 0 && year[2] == 0)
        {
            if(money < min_money)
            {
                min_money = money;
                idx = i;
            }
        }
    }

    cout << idx;
}