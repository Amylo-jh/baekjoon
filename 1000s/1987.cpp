#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

vector <vector <char>> board;
vector <bool> visited;
int r, c;
int max_move = 1;

void btrk(int y, int x, int depth)
{
    //right, down, left, up;
    int dy[4] = {0, -1, 0, 1};
    int dx[4] = {1, 0, -1, 0};

    for(int i = 0; i < 4; i++)
    {
        int next_y = y + dy[i];
        int next_x = x + dx[i];
        if(0 <= next_y && next_y < r && 0 <= next_x && next_x < c)
        {
            if(!visited[board[next_y][next_x] - 65])
            {
                depth++;
                if(depth > max_move)
                {
                    max_move = depth;
                }

                visited[board[next_y][next_x] - 65] = true;
                btrk(next_y, next_x, depth);
                visited[board[next_y][next_x] - 65] = false;
                depth--;
            }
        }
    }
}

int main()
{
    cin >> r >> c;
    board.resize(r);
    for(int i = 0; i < r; i++)
    {
        board[i].resize(c);
        string str;
        cin >> str;
        for(int j = 0; j < c; j++)
        {
            board[i][j] = str[j];
        }
    }

    visited.resize(26);
    visited[board[0][0] - 65] = true;
    btrk(0, 0, 1);
    cout << max_move;
}