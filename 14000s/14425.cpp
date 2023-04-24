#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    map <string, int> str_map;
    int counter = 0;

    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        str_map.insert({str, 1});
    }
    for(int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        counter += str_map[str];
    }
    cout << counter;
}