#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map <string, priority_queue<int>> info_seller;
    int query;
    long long total_value = 0;
    cin >> query;    

    for(int q = 0; q < query; q++)
    {
        int info_type;
        string name;
        int info_quantity;
        int info_get;

        cin >> info_type >> name;
        if(info_type == 1)
        {
            cin >> info_quantity;
            for(int i = 0; i < info_quantity; i++)
            {
                int temp;
                cin >> temp;
                info_seller[name].push(temp);
            }
        }
        else
        {
            cin >> info_get;
            if(info_seller.count(name) == 1)
            {
                while(info_get && !info_seller[name].empty())
                {
                    total_value += info_seller[name].top();
                    info_seller[name].pop();
                    info_get--;
                }
            }
        }
    }

    cout << total_value;
}