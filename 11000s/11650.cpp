#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct location
{
    int x;
    int y;
};

bool compare (location a, location b)
{
    if(a.x < b.x)
    {
        return true;
    }
    else if(a.x == b.x && a.y < b.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector <location> locations;

    for(int i = 0; i < n; i++)
    {
        location temp;
        cin >> temp.x >> temp.y;
        locations.push_back(temp);
    }

    sort(locations.begin(), locations.end(), compare);

    for(int i = 0; i < n; i++)
    {
        cout << locations[i].x << " " << locations[i].y << "\n";
    }
}