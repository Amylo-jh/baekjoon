#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    int k;
    vector <int> total_temperature;
    vector <int> subsum_temperature = {0};
    
    cin >> n >> k;

    int subsum = 0;

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        subsum = subsum + temp;
        total_temperature.push_back(temp);
        subsum_temperature.push_back(subsum);
    }

    int max_subsum = -9999999;

    for(int i = k; i <= n; i++)
    {
        if(max_subsum < subsum_temperature[i] - subsum_temperature[i-k])
        {
            max_subsum = subsum_temperature[i] - subsum_temperature[i-k];
        }
    }

    cout << max_subsum;

}