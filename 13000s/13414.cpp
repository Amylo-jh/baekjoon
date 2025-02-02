#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, n;
    cin >> k >> n;

    map <string, int> m;
    priority_queue <pair <int, string>, vector <pair <int, string>>, greater <pair <int, string>> > pq;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        m[str] = i;
    }

    for(auto it : m)
    {
        pq.push({it.second, it.first});
    }

    for(int i = 0; i < min(k, n); i++)
    {
        cout << pq.top().second << '\n';
        pq.pop();

        if(pq.empty())
        {
            break;
        }
    }
}