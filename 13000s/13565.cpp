#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector <vector <bool>> grid;
vector <vector <bool>> electric;
queue <pair<int, int>> bfs;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //맵 사이즈 초기화
    int n, m;
    cin >> n >> m;

    //맵 상태 입력
    for(int i = 0; i < n; i++)
    {
        vector <bool> temp_vec;
        vector <bool> temp_vec2;
        string str;
        cin >> str;
        for(int j = 0; j < m; j++)
        {
            if(str[j] == '1')
            {
                temp_vec.push_back(true);
            }
            else
            {
                temp_vec.push_back(false);
            }
            temp_vec2.push_back(false);
        }
        grid.push_back(temp_vec);
        electric.push_back(temp_vec2);
    }

    //맨 윗줄 전류 통하는 곳 bfs 큐에 넣는 초기 작업
    //큐에 넣음과 동시에 visited check
    for(int i = 0; i < m; i++)
    {
        if(!grid[0][i])
        {
            electric[0][i] = true;
            bfs.push({0,i});
        }
    }

    while(!bfs.empty())
    {
        int y = bfs.front().first; // down is n, y
        int x = bfs.front().second; // right is m, x
        bfs.pop();

        //sequence : left, down, right, up
        int search_x[4] = {x-1, x, x+1, x};
        int search_y[4] = {y, y+1, y, y-1};

        for(int i = 0; i < 4; i++)
        {
            //boundary check
            if(0 <= search_x[i] && search_x[i] < m
            && 0 <= search_y[i] && search_y[i] < n)
            {
                //if visited, continue, else check as visited;
                if(!grid[search_y[i]][search_x[i]] && !electric[search_y[i]][search_x[i]])
                {
                    electric[search_y[i]][search_x[i]] = true;
                    bfs.push({search_y[i],search_x[i]});
                }
            }
        }
    }

    bool flag = false;
    for(int i = 0; i < m; i++)
    {
        if(electric[n-1][i])
        {
            flag = true;
            break;
        }
    }

    if(flag)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}