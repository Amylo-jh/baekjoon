#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector <pair<int, int>> arr(n);
    vector <int> first(n);
    vector <int> second(n);
    vector <int> lis;
    vector <int> lis_tracking(n);

    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[i] = {a, b};
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++)
    {
        first[i] = arr[i].first;
        second[i] = arr[i].second;
    }

    lis.push_back(second[0]);
    lis_tracking[0] = 0;
    int ptr = 0;
    for(int i = 1; i < n; i++)
    {
        if(second[i] > lis[ptr])
        {
            lis.push_back(second[i]);
            ptr++;
            lis_tracking[i] = ptr;
            continue;
        }

        int pos = lower_bound(lis.begin(), lis.end(), second[i]) - lis.begin();
        lis[pos] = second[i];
        lis_tracking[i] = pos;
    }

    int counter = 0;
    vector <int> remove_line;
    for(int i = n-1; i >= 0; i--)
    {
        if(lis_tracking[i] != ptr)
        {
            counter++;
            remove_line.push_back(first[i]);
        }
        else
        {
            ptr--;
        }
    }
    cout << counter << "\n";
    for(int i = counter-1; i >= 0; i--)
    {
        cout << remove_line[i] << "\n";
    }
}