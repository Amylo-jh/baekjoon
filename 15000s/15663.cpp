#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, m;
vector <int> arr;
vector <bool> used;
set <vector <int>> s;


void btrk(int cnt, vector <int> v)
{
    if(cnt == m)
    {
        if(s.find(v) != s.end())
        {
            return;
        }
        for(int i : v)
        {
            cout << i << " ";
        }
        cout << "\n";
        s.insert(v);
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(used[i])
        {
            continue;
        }
        used[i] = true;
        v.push_back(arr[i]);
        btrk(cnt+1, v);
        used[i] = false;
        v.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.resize(n);
    used.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++)
    {
        vector <int> v;
        v.push_back(arr[i]);
        used[i] = true;
        btrk(1, v);
        v.pop_back();
        used[i] = false;
    }
}