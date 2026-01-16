#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, answer = 0;
    string str;
    map<string, int> mp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        mp[str]++;
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (mp[str])
        {
            answer++;
        }
    }
    cout << answer;
}