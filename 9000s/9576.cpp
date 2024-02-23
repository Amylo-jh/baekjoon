#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> arr;
vector <int> cache;
vector <int> match;

bool dfs(int v)
{
    cache[v] = 1;
    for(int next : arr[v])
    {
        if(cache[match[next]])
        {
            continue;
        }
        if(match[next] == 0 || dfs(match[next]))
        {
            match[next] = v;
            return true;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n, m;
        cin >> n >> m;
        arr = {};
        arr.resize(m+1);
        match = {};
        match.resize(n+1);
        for(int i = 1; i <= m; i++)
        {
            int a, b;
            cin >> a >> b;
            for(int j = a; j <= b; j++)
            {
                arr[i].push_back(j);
            }
        }

        int answer = 0;
        for(int i = 1; i <= m; i++)
        {
            cache = {};
            cache.resize(n+1);
            if(dfs(i))
            {
                answer++;
            }
        }

        cout << answer << "\n";
    }
}