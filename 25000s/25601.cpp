#include <iostream>
#include <queue>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    map <string, string> mp;
    for(int i = 1; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        mp[a] = b;
    }

    string a, b;
    cin >> a >> b;

    string curr = mp[a];
    while(curr != "")
    {
        if(curr == b)
        {
            cout << "1";
            return 0;
        }
        curr = mp[curr];
    }

    curr = mp[b];
    while(curr != "")
    {
        if(curr == a)
        {
            cout << "1";
            return 0;
        }
        curr = mp[curr];
    }

    cout << "0";
}