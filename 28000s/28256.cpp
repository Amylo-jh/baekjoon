#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        vector <vector <bool>> box(3);
        vector <vector <bool>> visited(3);
        for(int i = 0; i < 3; i++)
        {
            box[i].resize(3);
            visited[i].resize(3);
            string str;
            cin >> str;
            for(int j = 0; j < 3; j++)
            {
                if(str[j] == 'O')
                {
                    box[i][j] = true;
                }
                else
                {
                    box[i][j] = false;
                }
            }
        }

        int dy[4] = {-1, 0, 1, 0};
        int dx[4] = {0, 1, 0, -1};
        queue <pair <int, int>> bfs_queue;
        vector <int> found_choco;

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(box[i][j] && !visited[i][j])
                {
                    int curr_choco = 1;
                    visited[i][j] = true;
                    bfs_queue.push({i, j});
                    
                    while(!bfs_queue.empty())
                    {
                        int curr_y = bfs_queue.front().first;
                        int curr_x = bfs_queue.front().second;
                        bfs_queue.pop();

                        for(int k = 0; k < 4; k++)
                        {
                            int y = curr_y + dy[k];
                            int x = curr_x + dx[k];

                            if(0 <= y && y < 3 && 0 <= x && x < 3 && box[y][x] && !visited[y][x])
                            {
                                visited[y][x] = true;
                                bfs_queue.push({y, x});
                                curr_choco++;
                            }
                        }
                    }
                    found_choco.push_back(curr_choco);
                }
            }
        }
        sort(found_choco.begin(), found_choco.end());
        
        bool flag = true;
        int choco_count;
        cin >> choco_count;
        if(choco_count != found_choco.size())
        {
            flag = false;

            //dummy input
            for(int i = 0; i < choco_count; i++)
            {
                int input_num;
                cin >> input_num;
            }
        }
        else
        {
            for(int i = 0; i < choco_count; i++)
            {
                int input_num;
                cin >> input_num;
                if(input_num != found_choco[i])
                {
                    flag = false;
                }
            }
        }

        if(flag)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
}