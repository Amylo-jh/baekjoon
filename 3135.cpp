#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int start_freq;
    int target_freq;
    int n;
    vector <int> fav_freq_distance;

    cin >> start_freq >> target_freq;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        temp = abs(temp - target_freq) + 1;
        fav_freq_distance.push_back(temp);
    }

    int minimum_distance = abs(start_freq - target_freq);

    for(int i = 0; i < n; i++)
    {
        if(minimum_distance > fav_freq_distance[i])
        {
            minimum_distance = fav_freq_distance[i];
        }
    }

    cout << minimum_distance;
}