#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;


    vector <pair <int, string>> arr;
    vector <string> names;
    for(int i = 0; i < n; i++)
    {
        string name, attendance, is_win;
        int shake, apc;
        cin >> name >> attendance >> is_win >> shake >> apc;

        if(attendance == "hewhak" || is_win == "winner" || (1 <= shake && shake <= 3))
        {
            continue;
        }
        
        arr.push_back({apc, name});
    }

    sort(arr.begin(), arr.end());
    for(int i = 0; i < min(10, int(arr.size())); i++)
    {
        names.push_back(arr[i].second);
    }
    sort(names.begin(), names.end());

    cout << names.size() << "\n";
    for(auto i : names)
    {
        cout << i << "\n";
    }
}