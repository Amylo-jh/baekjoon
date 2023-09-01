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
        int temp;
        cin >> temp;
        mp[temp] = 1;
    }

    int m; 
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        cout << mp[temp] << " ";
    }
}