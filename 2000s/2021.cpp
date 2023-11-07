#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, l;
    cin >> n >> l;
    vector <vector <int>> stations(n+1);
    vector <bool> visited(n+1);
    vector <vector <int>> line(l);
    vector <bool> used(l);
    for(int i = 0; i < l; i++)
    {
        while(1)
        {
            int station;
            cin >> station;
            if(station < 0)
            {
                break;
            }
            stations[station].push_back(i);
            line[i].push_back(station);
        }
    }

    int start, end;
    cin >> start >> end;

    int dist = -1;
    queue <pair <int, int>> bfs_queue;
    for(int i : stations[start])
    {
        if(!used[i])
        {
            used[i] = true;
            for(int j : line[i])
            {
                if(!visited[j])
                {
                    visited[j] = true;
                    bfs_queue.push({j, 0});
                }
            }
        }
    }

    while(!bfs_queue.empty())
    {
        int curr_station = bfs_queue.front().first;
        int curr_dist = bfs_queue.front().second;
        bfs_queue.pop();

        if(curr_station == end)
        {
            dist = curr_dist;
            break;
        }
        for(int i : stations[curr_station])
        {
            if(!used[i])
            {
                used[i] = true;
                for(int j : line[i])
                {
                    if(!visited[j])
                    {
                        visited[j] = true;
                        bfs_queue.push({j, curr_dist+1});
                    }
                }
            }
        }
    }

    cout << dist;
}