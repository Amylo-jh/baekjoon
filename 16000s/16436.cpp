#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int w, h, k;
    cin >> w >> h >> k;

    vector <vector <int>> square(h+1, vector <int> (w+1));
    vector <vector <int>> diamond(h+1, vector <int> (w+1));
    for(int i = 0; i < k; i++)
    {
        int diagram, px, py, qx, qy, r;
        cin >> diagram;
        if(diagram == 1)
        {
            cin >> px >> py >> qx >> qy;
            square[py][px] += 1;
            square[qy+1][px] += -1;
            square[py][qx+1] += -1;
            square[qy+1][qx+1] += 1;
        }
        else
        {
            cin >> px >> py >> r;
            diamond[py-r][px] += 1;
            if(px-r-1 >= 0)
            {
                diamond[py+1][px-r-1] += -1;
            }
            diamond[py+1][px+r+1] += -1;
            if(py+r+2 < h+1)
            {
                diamond[py+r+2][px] += 1;
            }

            diamond[py-(r-1)][px] += 1;
            diamond[py+1][px-(r-1)-1] += -1;
            diamond[py+1][px+(r-1)+1] += -1;
            diamond[py+r+1][px] += 1;
        }
    }

    for(int i = 0; i < h; i++)
    {
        for(int j = 1; j < w; j++)
        {
            square[i][j] = square[i][j-1] + square[i][j];
        }
    }
    for(int j = 0; j < w; j++)
    {
        for(int i = 1; i < h; i++)
        {
            square[i][j] = square[i-1][j] + square[i][j];
        }
    }

    for(int i = 1; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            diamond[i][j] = diamond[i-1][j+1] + diamond[i][j];
        }
    }  
    for(int i = 1; i < h; i++)
    {
        for(int j = 1; j < w; j++)
        {
            diamond[i][j] = diamond[i-1][j-1] + diamond[i][j];
        }
    }

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            int result = square[i][j] + diamond[i][j];
            if(result % 2 == 0)
            {
                cout << ".";
            }
            else
            {
                cout << "#";
            }
        }
        cout << "\n";
    }
}