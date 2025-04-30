// n*m 사이즈의 배열이 주어지고, 해당 배열에서 1은 하얀색, 0은 검은색이다.
// 하얀색 영역의 개수와, 가장 넓은 하얀색 영역의 크기를 출력하라.

// tag : bfs, dfs, graphs, graph_traversal, implementation
// 예상 난이도 : 실2~실1

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int>> arr(n, vector <int>(m, 0));
    vector <vector <bool>> visited(n, vector <bool>(m, false));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int white_count = 0;
    int max_white = 0;

    queue <pair <int, int>> bfs_queue;
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!visited[i][j] && arr[i][j] == 1)
            {
                bfs_queue.push({i, j});
                visited[i][j] = true;
                int count = 1;
                
                while(!bfs_queue.empty())
                {
                    int curr_y = bfs_queue.front().first;
                    int curr_x = bfs_queue.front().second;
                    bfs_queue.pop();
                    
                    for(int k = 0; k < 4; k++)
                    {
                        int ny = curr_y + dy[k];
                        int nx = curr_x + dx[k];
                        
                        if(0 <= ny && ny < n && 0 <= nx && nx < m && !visited[ny][nx] && arr[ny][nx] == 1)
                        {
                            count++;
                            visited[ny][nx] = true;
                            bfs_queue.push({ny, nx});
                        }
                    }
                }
                
                white_count++;
                max_white = max(max_white, count);
            }
        }
    }

    cout << white_count << " " << max_white;
}