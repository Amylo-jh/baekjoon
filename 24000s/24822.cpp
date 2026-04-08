#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, count = 0;
    cin >> n >> m;
    vector<int> human(n);
    vector<int> tree(m);
    vector<bool> used(m);
    for (int i = 0; i < n; i++)
    {
        cin >> human[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> tree[i];
    }
    sort(human.begin(), human.end());
    sort(tree.begin(), tree.end());
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        int min_dist = INT32_MAX;
        int min_idx = 0;
        for (int j = 0; j < m; j++)
        {
            if (min_dist > abs(human[i] - tree[j]))
            {
                min_dist = abs(human[i] - tree[j]);
                min_idx = j;
            }
        }
        used[min_idx] = true;
    }
    for (int i = 0; i < m; i++)
    {
        if (used[i])
        {
            count++;
        }
    }
    cout << n - count;
}