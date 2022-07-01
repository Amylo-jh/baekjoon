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

int verify_x(int x, int y)
{
    int user = board[x][y];
    int combo = 0;
    int max_combo = 0;
    
    for(int i = -5; i < 6; i++)
    {
        if(y+i >= 19 && y+i <= 0)
        {
            continue;
        }

        if(board[x][y+i] != user)
        {
            if(combo == 0)
            {
                continue;
            }
            else
            {
                combo = 0;
            }
        }
        else
        {
            combo++;
            if(max_combo < combo)
            {
                max_combo = combo;
            }
        }
    }

    if(max_combo == 5)
    {
        return user;
    }
    
    return 0;
}

int verify_y(int x, int y)
{
    int user = board[x][y];
    int combo = 0;
    int max_combo = 0;
    
    for(int i = -5; i < 6; i++)
    {
        if(x+i >= 19 && x+i <= 0)
        {
            continue;
        }

        if(board[x+i][y] != user)
        {
            if(combo == 0)
            {
                continue;
            }
            else
            {
                combo = 0;
            }
        }
        else
        {
            combo++;
            if(max_combo < combo)
            {
                max_combo = combo;
            }
        }
    }

    if(max_combo == 5)
    {
        return user;
    }
    
    return 0;
}

int verify_xy(int x, int y)
{
    int user = board[x][y];
    int combo = 0;
    int max_combo = 0;
    
    for(int i = -5; i < 6; i++)
    {
        if( (x+1 >= 19 && x+i <= 0) || (y+i >= 19 && y+i <= 0) )
        {
            continue;
        }

        if(board[x+i][y+i] != user)
        {
            if(combo == 0)
            {
                continue;
            }
            else
            {
                combo = 0;
            }
        }
        else
        {
            combo++;
            if(max_combo < combo)
            {
                max_combo = combo;
            }
        }
    }

    if(max_combo == 5)
    {
        return user;
    }
    
    return 0;
}

int verify_reverse_xy(int x, int y)
{
    int user = board[x][y];
    int combo = 0;
    int max_combo = 0;
    bool flag = false;
    
    for(int i = -1; i < 6; i++)
    {
        if( (x+1 >= 19 && x+i <= 0) || (y-i >= 19 && y-i <= 0) )
        {
            continue;
        }

        if(board[x-i][y+i] != user)
        {
            if(combo == 0)
            {
                continue;
            }
            else
            {
                combo = 0;
            }
        }
        else
        {
            if(i == -1)
            {
                flag = true;
            }
            combo++;
            if(max_combo < combo)
            {
                max_combo = combo;
            }
        }
    }

    if(max_combo == 5 && flag == false)
    {
        return user;
    }
    
    return 0;
}


int verify(int x, int y)
{
    int winner = 0;

    if(y < 15 && winner == 0)
    {
        winner = verify_x(x, y);
    }
    if(x < 15 && winner == 0)
    {
        winner = verify_y(x, y);
    }
    if(x < 15 && y < 15 && winner == 0)
    {
        winner = verify_xy(x, y);
    }
    if(x > 3 && y < 15 && winner == 0)
    {
        winner = verify_reverse_xy(x, y);
    }

    return winner;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 19; i++)
    {
        for(int j = 0; j < 19; j++)
        {
            cin >> board[i][j];
        }
    }

    int winner = 0;
    int x = 0;
    int y = 0;

    for(int i = 0; i < 19; i++)
    {
        for(int j = 0; j < 19; j++)
        {
            if(board[i][j] != 0 && winner == 0)
            {
                winner = verify(i, j);
            }

            if(winner != 0)
            {
                x = i;
                y = j;
                break;
            }
        }

        if(winner != 0)
        {
            break;
        }
    }

    cout << winner << endl;
    if(winner != 0)
    {
        cout << x+1 << " " << y+1;
    }

}