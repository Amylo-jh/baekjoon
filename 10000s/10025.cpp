#include <iostream>

using namespace std;

int main()
{
    int cage[1000001] = {0};
    
    int bucket;
    int k;
    int total_ice = 0;

    cin >> bucket >> k;

    for(int i = 0; i < bucket; i++)
    {
        int ice_temp;
        int location_temp;
        cin >> ice_temp >> location_temp;

        cage[location_temp] = ice_temp;
        total_ice += ice_temp;
    }

    int max_ice = 0;
    int curr_ice = 0;

    if(k >= 1000000)
    {
        cout << total_ice;
        return 0;
    }

    for(int i = 0; i <= 2 * k; i++)
    {
        max_ice += cage[i];
    }

    curr_ice = max_ice;

    for(int i = 2*k + 1; i <= 1000000; i++)
    {
        curr_ice += cage[i];
        curr_ice -= cage[i- (2 *k +1)];

        if(curr_ice > max_ice)
        {
            max_ice = curr_ice;
        }
    }
    
    cout << max_ice;
}