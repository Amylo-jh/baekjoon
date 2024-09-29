#include <iostream>
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

    map <string, int> m;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        m[str]++;
    }
    for(int i = 1; i < n; i++)
    {
        string str;
        cin >> str;
        m[str]--;
    }
    for(auto it : m)
    {
        if(it.second != 0)
        {
            cout << it.first;
            break;
        }
    }
}