#include <iostream>
#include <vector>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) < (b)) ? (b) : (a))

using namespace std;

int main()
{
    vector <int> lans;
    int k;
    int target;
    cin >> k >> target;

    long long lan_max = 0;
    long long lan_min = 1;
    long long lan_middle;

    for(int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        lan_max = max(lan_max, temp);
        
        lans.push_back(temp);
    }

    while(lan_min <= lan_max)
    {
        lan_middle = (lan_min + lan_max) / 2;

        int curr_lans = 0;

        for(int lan : lans)
        {
            curr_lans += lan / lan_middle;
        }

        if(curr_lans >= target)
        {
            lan_min = lan_middle + 1;
        }
        else
        {
            lan_max = lan_middle - 1;
        }
    }

    cout << max(lan_max, lan_min) - 1;
}