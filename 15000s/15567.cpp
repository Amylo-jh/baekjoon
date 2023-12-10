#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> arr;
int n, m;

void btrk(int a, int b, vector <int> v)
{
    if(b == m)
    {
        for(int i : v)
        {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = a; i < n; i++)
    {
        v.push_back(arr[i]);
        btrk(i, b+1, v);
        v.pop_back();
    }
}

int main()
{  
    cin >> n >> m;
    arr.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++)
    {
        vector <int> v;
        v.push_back(arr[i]);
        btrk(i, 1, v);
        v.pop_back();
    }
}