#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    map <int, int> mp;
    for(int i = 0; i < n; i++)
    {
        int query, x, w;
        cin >> query;
        if(query == 1)
        {
            cin >> x >> w;
            mp[w] = x;
        }
        else if(query == 2)
        {
            cin >> w;
            cout << mp[w] << "\n";
        }
    }
}