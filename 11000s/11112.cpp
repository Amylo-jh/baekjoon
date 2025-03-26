#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map <vector <vector <int>>, int> mp;
    vector <vector <int>> arr{{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    queue <pair <vector <vector <int>>, pair <int, int>>> bfs_queue;
    bfs_queue.push({arr, {2, 2}}); 
    mp[arr] = 0;
    
    int dy[4] = {0, 0, 1, -1};
    int dx[4] = {1, -1, 0, 0};
    vector <vector <int>> curr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    vector <vector <int>> next = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    while(!bfs_queue.empty())
    {
        curr = bfs_queue.front().first;
        int y = bfs_queue.front().second.second;
        int x = bfs_queue.front().second.first;
        int dist = mp[curr];
        bfs_queue.pop();

        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0 <= ny && ny < 3 && 0 <= nx && nx < 3)
            {
                next = curr;
                swap(next[y][x], next[ny][nx]);
                if(mp.find(next) == mp.end() || mp[next] > dist + 1)
                {
                    mp[next] = dist + 1;
                    bfs_queue.push({next, {nx, ny}});
                }
            }
        }
    }
    mp[{{1, 2, 3}, {4, 5, 6}, {7, 8, 0}}] = 0;

    int tc;
    cin >> tc;
    while(tc--)
    {
        string str;
        for(int i = 0; i < 3; i++)
        {
            cin >> str;
            for(int j = 0; j < 3; j++)
            {
                if(str[j] == '#')
                {
                    arr[i][j] = 0;
                }
                else
                {
                    arr[i][j] = str[j] - '0';
                }
            }
        }

        if(mp.find(arr) == mp.end())
        {
            cout << "impossible" << '\n';
        }
        else
        {
            cout << mp[arr] << '\n';
        }
    }
}