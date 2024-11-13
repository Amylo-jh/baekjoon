#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    map <string, int> mp;
    int warn = 0;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        int count = mp[str];

        if(i-count < count)
        {
            warn++;
        }
        mp[str]++;

    }

    cout << warn;
}