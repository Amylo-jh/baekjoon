#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair <int, pair <int, int>>> arr;
vector <pair <int, int>> x;
vector <pair <int, int>> y;
vector <pair <int, int>> z;
vector <int> parent;

int find(int a)
{
    if(parent[a] == a)
    {
        return a;
    }

    return parent[a] = find(parent[a]);
}

void make_union(int a, int b)
{
    a = find(a);
    b = find(b);

    if(a < b)
    {
        parent[b] = a;
    }
    else
    {
        parent[a] = b;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    parent.resize(n+1, 0);

    for(int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        x.push_back({a, i});
        y.push_back({b, i});
        z.push_back({c, i});
        parent[i] = i;
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    for(int i = 0; i < n-1; i++)
    {
        arr.push_back({x[i+1].first - x[i].first, {x[i].second, x[i+1].second}});
        arr.push_back({y[i+1].first - y[i].first, {y[i].second, y[i+1].second}});
        arr.push_back({z[i+1].first - z[i].first, {z[i].second, z[i+1].second}});
    }

    sort(arr.begin(), arr.end());

    int sum = 0;

    for(int i = 0; i < arr.size(); i++)
    {
        int a = arr[i].second.first;
        int b = arr[i].second.second;
        int c = arr[i].first;

        if(find(a) != find(b))
        {
            make_union(a, b);
            sum += c;
        }
    }

    cout << sum;
}