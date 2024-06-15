#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector <int> arr;
vector <int> enemy;

int find_parent(int a)
{
    if(arr[a] == a)
    {
        return a;
    }
    return arr[a]= find_parent(arr[a]);
}

int find_enemy(int a, int b)
{
    if(enemy[a] == 0)
    {
        return enemy[a] = b;
    }
    return enemy[a];
}

void make_union(int a, int b)
{
    int pa = find_parent(a);
    int pb = find_parent(b);

    if(pa != pb)
    {
        arr[pb] = pa;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    arr.resize(n+1);
    enemy.resize(n+1);
    for(int i = 1; i <= n; i++)
    {
        arr[i] = i;
    }

    for(int i = 0; i < m; i++)
    {
        string s;
        int a, b;
        cin >> s >> a >> b;

        if(s == "E")
        {
            make_union(a, find_enemy(b, a));
            make_union(b, find_enemy(a, b));
        }
        else
        {
            make_union(a, b);
        }
    }

    map <int, int> mp;
    for(int i = 1; i <= n; i++)
    {
        mp[find_parent(i)]++;
    }

    cout << mp.size();
}