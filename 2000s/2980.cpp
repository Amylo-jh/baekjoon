#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, l;
    cin >> n >> l;

    // pos, red, green;
    vector <pair <int, pair <int, int>>> light(n);
    for(int i = 0; i < n; i++)
    {
        cin >> light[i].first >> light[i].second.first >> light[i].second.second;
    }

    int time = 0;
    int pos = 0;
    for(int i = 0; i < n; i++)
    {
        int next_dist = light[i].first - pos;
        
        time += next_dist;
        pos = light[i].first;
        if(time % (light[i].second.first + light[i].second.second) < light[i].second.first)
        {
            time += light[i].second.first - (time % (light[i].second.first + light[i].second.second));
        }
    }
    time += l - pos;
    cout << time << "\n";
}