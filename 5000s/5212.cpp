#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;
    vector <vector <bool>> arr(r, vector <bool>(c, false));
    vector <vector <bool>> after(r, vector <bool>(c, false));
    for(int i = 0; i < r; i++)
    {
        string str;
        cin >> str;
        for(int j = 0; j < c; j++)
        {
            if(str[j] == 'X')
            {
                arr[i][j] = true;
            }
        }
    }

    int dy[4] = {0, 0, 1, -1};
    int dx[4] = {1, -1, 0, 0};

    int min_y = 100;
    int max_y = 0;
    int min_x = 100;
    int max_x = 0;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(!arr[i][j])
            {
                continue;
            }
            int cnt = 0;
            for(int k = 0; k < 4; k++)
            {
                int y = i + dy[k];
                int x = j + dx[k];
                if(0 <= y && y < r && 0 <= x && x < c)
                {
                    if(arr[y][x])
                    {
                        cnt++;
                    }
                }

            }
            if(cnt > 1)
            {
                after[i][j] = true;
                min_y = min(min_y, i);
                max_y = max(max_y, i);
                min_x = min(min_x, j);
                max_x = max(max_x, j);
            }
        }
    }

    for(int i = min_y; i <= max_y; i++)
    {
        for(int j = min_x; j <= max_x; j++)
        {
            if(after[i][j])
            {
                cout << "X";
            }
            else
            {
                cout << ".";
            }
        }
        cout << "\n";
    }
}