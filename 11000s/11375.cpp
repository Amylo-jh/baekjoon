#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector <vector <int>> labor;
vector <bool> cache;
vector <int> match;

bool dfs(int v)
{
    cache[v] = true;
    for(int next : labor[v])
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

    cin >> n >> m;
    labor.resize(n+1);
    cache.resize(n+1);
    match.resize(m+1);

    for(int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        labor[i].resize(a);
        for(int j = 0; j < a; j++)
        {
            cin >> labor[i][j];
        }
    }

    int answer = 0;
    for(int i = 1; i <= n; i++)
    {
        fill(cache.begin(), cache.end(), 0);
        if(dfs(i))
        {
            answer++;
        }
    }

    cout << answer;
}