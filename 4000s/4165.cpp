#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

map <string, int> name;
vector <pair <int, int>> parent;

int find(int a)
{
    if(parent[a].first != a)
    {
        return find(parent[a].first);
    }
    return a;
}

void make_union(int a, int b)
{
    a = find(a);
    b = find(b);

    if(a != b)
    {
        parent[b].first = a;
        parent[a].second += parent[b].second;
        parent[b].second = 0;
    }
}

void solve()
{
    name.clear();
    parent.clear();
    
    int f;
    cin >> f;
    for(int i = 0; i < f; i++)
    {
        string a, b;
        int a_index, b_index;
        cin >> a >> b;

        if(name.find(a) == name.end())
        {
            name.insert({a, parent.size()});
            parent.push_back({parent.size(), 1});
        }
        
        if(name.find(b) == name.end())
        {
            name.insert({b, parent.size()});
            parent.push_back({parent.size(), 1});
        }
        a_index = name[a];
        b_index = name[b];
        make_union(a_index, b_index);

        cout << parent[find(a_index)].second << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--)
    {
        solve();
    }
}