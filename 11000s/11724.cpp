#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> dots;
vector<bool> visited;

void init_bfs(int i)
{
    queue <int> bfs;
    bfs.push(i);

    while(!bfs.empty())
    {
        int curr_search = bfs.front();
        visited[curr_search] = true;
        bfs.pop();

        for(int j : dots[curr_search])
        {
            if(visited[j])
            {
                continue;
            }
            else
            {
                bfs.push(j);
                visited[j] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        dots.push_back({});
        visited.push_back(false);
    }

    for(int i = 0; i < m; i++)
    {   
        int d1, d2;
        cin >> d1 >> d2;
        d1--;
        d2--;
        dots[d1].push_back(d2);
        dots[d2].push_back(d1);
    }

    int connected_node = 0;
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == false)
        {
            init_bfs(i);
            connected_node++;
        }
    }

    cout << connected_node;
}