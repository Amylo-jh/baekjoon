#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector <vector <bool>> arr(n, vector <bool>(m, false));
    vector <vector <bool>> visited(n, vector <bool>(m, false));
    for(int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < m; j++)
        {
            if(tmp[j] == '1')
            {
                arr[i][j] = true;
            }
        }
    }
    vector <int> count;
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] && !visited[i][j])
            {
                queue <pair <int, int>> bfs_queue;
                bfs_queue.push({i, j});
                visited[i][j] = true;
                int curr_count = 1;

                while(!bfs_queue.empty())
                {
                    int curr_y = bfs_queue.front().first;
                    int curr_x = bfs_queue.front().second;
                    bfs_queue.pop();

                    for(int k = 0; k < 4; k++)
                    {
                        int ny = curr_y + dy[k];
                        int nx = curr_x + dx[k];
                        if(0 <= ny && ny < n && 0 <= nx && nx < m && arr[ny][nx] && !visited[ny][nx])
                        {
                            bfs_queue.push({ny, nx});
                            visited[ny][nx] = true;
                            curr_count++;
                        }
                    }
                }               
                count.push_back(curr_count);
            }
        }
    }

    sort(count.begin(), count.end());
    cout << count.size() << "\n";
    for(int i : count)
    {
        cout << i << " ";
    }
}