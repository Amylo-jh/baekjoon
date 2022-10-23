#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct bus
{
    int start = 0;
    int end = 0;
    int cost = 0;
};

bool comp(bus a, bus b)
{
    if(a.start < b.start)
    {
        return a.start < b.start;
    }
    else if(a.start == b.start)
    {
        return a.end < b.end;
    }
    return a.start < b.start;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector <bus> old_buses(n);
    vector <bus> new_buses;
    for(int i = 0; i < n; i++)
    {
        int s, e, c;
        cin >> old_buses[i].start >> old_buses[i].end >> old_buses[i].cost;
    }

    sort(old_buses.begin(), old_buses.end(), comp);


    int s = old_buses[0].start;
    int e = old_buses[0].end;
    int c = old_buses[0].cost;

    for(int i = 0; i < n; i++)
    {
        if(e < old_buses[i].start)
        {
            new_buses.push_back({s, e, c});
            s = old_buses[i].start;
            e = old_buses[i].end;
            c = old_buses[i].cost;
        }

        e = max(e, old_buses[i].end);
        c = min(c, old_buses[i].cost);
    }
    new_buses.push_back({s, e, c});
    
    cout << new_buses.size() << "\n";
    for(int i = 0; i < new_buses.size(); i++)
    {
        cout << new_buses[i].start << " " << new_buses[i].end << " " << new_buses[i].cost << "\n";
    }
}