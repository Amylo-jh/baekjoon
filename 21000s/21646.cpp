#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> forward_sector;
vector <int> reverse_sector;
int n;
int init_speed_min;
int init_speed_max;
int k;

pair <int, int> get_sector(vector <int> &sector, int speed)
{
    pair <int, int> return_value;
    int rotate = ((speed / k) - 1) / n;
    int curr_sector = speed / k;
    if(speed % k == 0)
    {
        curr_sector--;
    }

    curr_sector %= n;

    return_value.first = rotate;
    return_value.second = curr_sector;
    return return_value;
}

int seek_max_value(vector <int> &sector, pair <int, int> min_sector, pair <int, int> max_sector)
{
    vector <int> seekable_sector;
    int diff_rotate = max_sector.first - min_sector.first;
    int diff_sector = max_sector.second - min_sector.second;
    if(diff_sector < 0)
    {
        diff_rotate--;
        diff_sector += n;
    }

    if(diff_rotate >= 1 || diff_sector > n-1)
    {
        seekable_sector = sector;
    }
    else
    {
        for(int i = 0; i <= diff_sector; i++)
        {
            int iter = i + min_sector.second;
            iter %= n;
            seekable_sector.push_back(sector[iter]);
        }
    }

    sort(seekable_sector.begin(), seekable_sector.end(), greater<>());
    
    return seekable_sector[0];
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        forward_sector.push_back(temp);
    }
    reverse_sector.push_back(forward_sector[0]);
    for(int i = n-1; i > 0; i--)
    {
        reverse_sector.push_back(forward_sector[i]);
    }

    cin >> init_speed_min >> init_speed_max >> k;

    //pair = rotates, curr_sector;
    pair <int, int> forward_min_sector = get_sector(forward_sector, init_speed_min);
    pair <int, int> forward_max_sector = get_sector(forward_sector, init_speed_max);
    pair <int, int> backward_min_sector = get_sector(reverse_sector, init_speed_min);
    pair <int, int> backward_max_sector = get_sector(reverse_sector, init_speed_max);

    int max_value = 0;

    max_value = max(max_value, seek_max_value(forward_sector, forward_min_sector, forward_max_sector));
    max_value = max(max_value, seek_max_value(reverse_sector, backward_min_sector, backward_max_sector));

    cout << max_value;
}