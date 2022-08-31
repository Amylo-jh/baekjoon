#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare (pair <long long, long long> a, pair <long long, long long> b)
{
    return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;
    //tree, grow
    vector <pair <long long, long long>> tree(n);
    for(int i = 0; i < n; i++)
    {
        cin >> tree[i].first;
    }
    
    for(int i = 0; i < n; i++)
    {
        cin >> tree[i].second;
    }

    sort(tree.begin(), tree.end(), compare);

    long long total_tree = 0;

    for(int i = 0; i < n; i++)
    {
        total_tree += tree[i].first + tree[i].second * i;
    }

    cout << total_tree;
}