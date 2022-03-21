#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int city_num;
    cin >> city_num;

    vector <int> citys;
    int total_budget;
    
    for(int i = 0; i < city_num; i++)
    {
        int temp;
        cin >> temp;
        citys.push_back(temp);
    }

    cin >> total_budget;

    sort(citys.begin(), citys.end());

    int avg = total_budget / city_num;
    int max_assign_budget = 0;

    for(int i = 0; i < city_num; i++)
    {
        if(avg >= citys[i])
        {
            max_assign_budget = citys[i];
            total_budget = total_budget - citys[i];

            if(i == city_num -1)
            {
                continue;
            }
            avg = total_budget / (city_num - i - 1);
        }
        else
        {
            max_assign_budget = avg;
            break;
        }
    }

    cout << max_assign_budget;
}