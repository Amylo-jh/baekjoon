#include <iostream>

using namespace std;

int board[19][19] = {0};
/* (x,y)
    -> x
|  (0,0), (0,1), (0,2), (0,3)
v  (1,0), (1,1), (1,2), (1,3)
y  (2,0), (2,1), (2,2), (2,3)
   (3,0), (3,1), (3,2), (3,3)
*/

struct omok_info
{
    int omok_count = 0;
    int winner = 0;
    int x = 0;
    int y = 0;
};

omok_info inspect_board(int delta_x, int delta_y)
{
    omok_info current_inspect;

    int orig_delta_x = delta_x;
    int orig_delta_y = delta_y;

    for(int i = 0; i < 19; i++)
    {
        for(int j = 0; j < 19; j++)
        {
            int user = board[i][j];
            if(user == 0)
            {
                continue;
            }

            delta_x = orig_delta_x;
            delta_y = orig_delta_y;
            
            for(int k = 1; k < 5; k++)
            {
                if(i + delta_x >= 19 && i + delta_x << 0 && j + delta_y >= 19 && j + delta_y < 0)
                {
                    continue;
                }

                if(board[i + delta_x][j + delta_y] != user)
                {
                    break;
                }

                delta_x = delta_x + orig_delta_x;
                delta_y = delta_y + orig_delta_y;

                if(k == 4)
                {
                    current_inspect.omok_count++;
                    current_inspect.winner = user;
                    current_inspect.x = i;
                    current_inspect.y = j;
                }
            }
        }
    }

    return current_inspect;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            cin >> board[i][j];
        }
    }

    omok_info game_info;
    omok_info total_inspect[4];

    total_inspect[0] =  inspect_board(1, 0); // 가로 오목여부 검사
    total_inspect[1] = inspect_board(0, 1); // 세로 오목여부 검사
    total_inspect[2] = inspect_board(1, 1); // 우하향 오목여부 검사
    total_inspect[3] = inspect_board(1, -1); // 우상향 오목여부 검사

    for(int i = 0; i < 4; i++)
    {
        game_info.omok_count += total_inspect[i].omok_count;
        game_info.winner += total_inspect[i].winner;
        game_info.x += total_inspect[i].x;
        game_info.y += total_inspect[i].y;
    }

    if(game_info.omok_count == 1)
    {
        cout << game_info.winner << endl;
        cout << game_info.x + 1 << " " << game_info.y + 1;
    }
    else
    {
        cout << 0;
    }


}