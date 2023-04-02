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
    vector <int> distance(n-1);
    vector <int> city(n-1);

    for(int i = 0; i < n-1; i++)
    {
        cin >> distance[i];
    }
    for(int i = 0; i < n-1; i++)
    {
        cin >> city[i];
    }

    long long price = 0;
    for(int i = 0; i < n-1;)
    {
        long long curr_dist = distance[i];
        long long curr_price = city[i];
        while(i < n-1)
        {
            if(curr_price < city[i+1])
            {
                curr_dist += distance[i+1];
                i++;
            }
            else
            {
                break;
            }
        }
        price += curr_dist * curr_price;
        i++;
    }

    cout << price;
}